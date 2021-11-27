#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h> // for rand()
#include <unistd.h> // for sleep
#include <stdio.h>

const int STUDENTS = 5;
const int PIZZA_SLICES = 4;

pthread_mutex_t control_mutex;
sem_t order_pizza;
sem_t pizza_slice;

void *student(void *args)
{
    int *i = (int *)args;
    while (1)
    {
        pthread_mutex_lock(&control_mutex);
        if (sem_trywait(&pizza_slice) != 0)
        {
            // Order Pizza if you dont get slice and wait until u get a slice
            sem_post(&order_pizza);
            printf("Student %d: Orders Pizza\n", i);
            sem_wait(&pizza_slice);
        }
        printf("Student %d: Gets pizza slize\n", i);
        pthread_mutex_unlock(&control_mutex);

        sleep(1 + rand() % 5); // Student studies
    }
}

void *delivery(void* args)
{
    while (1)
    {
        // Delivery guy waits until order is complete
        sem_wait(&order_pizza);
        sleep(1 + rand() % 5); // Delivery Time
        for(int i = 0; i < PIZZA_SLICES; i++){
            sem_post(&pizza_slice);
        }
        printf("Delivery guy completed delivery\n");

    }
    printf("Delivery guy exited\n");
}

int main()
{
    pthread_t students[STUDENTS], delivery_guy;
    pthread_mutex_init(&control_mutex, NULL);
    sem_init(&pizza_slice, 0, PIZZA_SLICES); // Asumming we already have 1 pizza(can be set to zero too)
    sem_init(&order_pizza, 0, 0);

    printf("Press Ctrl + C to terminate the program\n");

    for(int i = 0; i < STUDENTS; i++){
        // Not dynamically allocation memory and using the 
        // argument pointer value as an identifier for the thread
        pthread_create(&students[i], NULL, student, i+1);
    }
    pthread_create(&delivery_guy, NULL, delivery, 0);

    getchar();  // Waiting for user input before exit
    return 0;
}
