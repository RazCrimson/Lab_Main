#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h> // for rand()
#include <unistd.h> // for sleep
#include <stdio.h>

const int BARBERS = 2;
const int WAITING_CHAIRS = 3;
const int WAITING_BENCH_LIMIT = 3;

const int TOTAL_CUSTOMERS = 25;

pthread_mutex_t shop_mutex; // Used to make sure customers leave only if there is no space 
sem_t barbers;
sem_t customers;
sem_t waiting_chairs;
sem_t waiting_bench;

void *barber_wait(void *args)
{
    int *i = (int *)args;
    while (1)
    {
        sem_post(&barbers);
        sem_wait(&customers);

        sleep(5 + rand() % 5); // Perform a haircut
        printf("Barber %d: Finished Haircut\n", *i);
    }
}

void *customer_wait(void *args)
{
    int *i = (int *)args;
    pthread_mutex_lock(&shop_mutex);
    if (sem_trywait(&waiting_bench) == 0)
    {
        printf("%d: Gets Waiting Bench\n", *i);
        sem_post(&customers);
        pthread_mutex_unlock(&shop_mutex);

        sem_wait(&waiting_chairs);
        printf("%d: Switches to Waiting Chair\n", *i);

        pthread_mutex_lock(&shop_mutex);
        sem_post(&waiting_bench);
        pthread_mutex_unlock(&shop_mutex);

        sem_wait(&barbers);
        sem_post(&waiting_chairs);
        printf("%d: Switches to Barber Seat\n", *i);
    }
    else
    {
        pthread_mutex_unlock(&shop_mutex);
        printf("%d: Leaves as Shop is filled!\n", *i);
    }
    free(args);
}

int main()
{
    pthread_mutex_init(&shop_mutex, NULL);
    sem_init(&waiting_bench, 0, WAITING_BENCH_LIMIT);
    sem_init(&waiting_chairs, 0, WAITING_CHAIRS);
    sem_init(&customers, 0, 0);
    sem_init(&barbers, 0, 0);

    pthread_t customers[TOTAL_CUSTOMERS], barber_threads[BARBERS];
    for (int i = 0; i < BARBERS; i++)
    {
        int *args = malloc(sizeof(int));
        *args = i;
        pthread_create(&barber_threads[i], NULL, barber_wait, args);
    }

    for (int i = 0; i < TOTAL_CUSTOMERS; i++)
    {
        int *args = malloc(sizeof(int));
        *args = i;
        pthread_create(&customers[i], NULL, customer_wait, args);
        sleep(rand() % 4);
    }
    for (int i = 0; i < TOTAL_CUSTOMERS; i++)
        pthread_join(customers[i], NULL);

    sleep(10); // Waiting for Barber to complete last haircut
    printf("Please Exit program as barber threads are not meant to die automatically\n");
    for (int i = 0; i < BARBERS; i++)
        pthread_join(barber_threads[i], NULL);
}