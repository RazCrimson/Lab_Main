#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h> // for rand()
#include <unistd.h> // for sleep
#include <stdio.h>

const int CONTINUOUS_CARS_LIMIT = 15;
const int TOTAL_CARS_LIMIT = 130;
const int SWITCH_LIMIT = 7;

typedef enum
{
    NORTH,
    SOUTH,
    FREE
} TUNNEL_STATES;

pthread_mutex_t tunnel_mutex;
int wait_count[2];
sem_t wait_list[2];

TUNNEL_STATES tunnel = FREE;
int current_count = 0;
int starve_count = 0;

void enter(TUNNEL_STATES dir, int i)
{
    do
    {
        pthread_mutex_lock(&tunnel_mutex);
        if (tunnel == !dir ||
            (tunnel == dir && (wait_count[!dir] > 0 && starve_count >= SWITCH_LIMIT)))
        {
            wait_count[dir]++;
            pthread_mutex_unlock(&tunnel_mutex);
            sem_wait(&wait_list[dir]);

            pthread_mutex_lock(&tunnel_mutex);
            wait_count[dir]--;
            pthread_mutex_unlock(&tunnel_mutex);
            continue;
        }
        tunnel = dir;
        current_count++;
        starve_count++;
        printf("Entering | Car: %d in DIR: %d \n", i, dir);
        pthread_mutex_unlock(&tunnel_mutex);
        return;
    } while (1);
}

void leave(TUNNEL_STATES dir, int i)
{
    int opposite_count;
    pthread_mutex_lock(&tunnel_mutex);
    current_count--;
    if (current_count == 0)
    {
        starve_count = 0;
        tunnel = FREE;
        printf("Leaving: %d waking up %d threads of DIR: %d\n", i, wait_count[!dir], !dir);
        opposite_count = wait_count[!dir];
        while (opposite_count > 0)
        {
            sem_post(&wait_list[!dir]);
            opposite_count--;
        }
    }
    pthread_mutex_unlock(&tunnel_mutex);
}

void *thread_helper(void *args)
{
    int *values = (int *)args;
    enter(values[1], values[0]);
    sleep(5 + rand() % 5);
    leave(values[1], values[0]);
    free(args);
}

int main()
{
    pthread_t t[TOTAL_CARS_LIMIT];
    pthread_mutex_init(&tunnel_mutex, NULL);
    for (int i = 0; i < 2; i++)
        sem_init(&wait_list[i], 0, 0);

    for (int i = 0; i < TOTAL_CARS_LIMIT;)
    {
        int n = rand() % CONTINUOUS_CARS_LIMIT;
        for (int j = 0; i < TOTAL_CARS_LIMIT && j < n; j++, i++)
        {
            int *args = (int *)malloc(sizeof(int) * 2);
            args[0] = i;     // thread counter
            args[1] = i % 2; // direction
            pthread_create(&t[i], NULL, thread_helper, args);
        }
    }
    for (int i = 0; i < TOTAL_CARS_LIMIT; i++)
        pthread_join(t[i], NULL);
}