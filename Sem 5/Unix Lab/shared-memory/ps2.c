#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void die(char *message)
{
    perror(message);
    exit(1);
}

int main()
{
    double *shmPtr;
    int shmId, size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int SHMSIZE = (size + 3) * sizeof(double);
    key_t key = ftok(__FILE__, 1);

    if (fork() > 0)
    {
        if (fork() > 0)
        {
            shmId = shmget(key, SHMSIZE, IPC_CREAT | 0666);
            if (shmId < 0)
                die("shmget");
            shmPtr = (double *)shmat(shmId, NULL, 0);
            if (shmPtr == (double *)-1)
                die("shmat");
            *shmPtr = -1;
            printf("Enter the numbers:\n");
            for (int i = 1; i < size + 1; i++)
            {
                double input;
                scanf("%lf", &input);
                *(shmPtr + i) = input;
            }
            *shmPtr = -2;
            wait(NULL);
            wait(NULL);

            printf("Smallest integer is: %.2lf\n", *(shmPtr + size + 1));
            printf("Average is: %.2lf\n", *(shmPtr + size + 2));
            
            shmdt(shmPtr);
            shmctl(shmId, IPC_RMID, NULL);
        }
        else
        {
            shmId = shmget(key, SHMSIZE, IPC_CREAT | 0666);
            if (shmId < 0)
                die("shmget");

            shmPtr = (double *)shmat(shmId, NULL, 0);
            if (shmPtr == (double *)-1)
                die("shmat");

            while (*shmPtr != -2)
                sleep(0.1);

            printf("Finding Minimum\n");
            double min = *(shmPtr + 1);
            for (int i = 1; i < size + 1; i++)
            {
                if (min > *(shmPtr + i))
                    min = *(shmPtr + i);
            }
            *(shmPtr + size + 1) = min;
            shmdt(shmPtr);
        }
    }
    else
    {
        shmId = shmget(key, SHMSIZE, IPC_CREAT | 0666);
        if (shmId < 0)
            die("shmget");

        shmPtr = (double *)shmat(shmId, NULL, 0);
        if (shmPtr == (double *)-1)
            die("shmat");

        while (*shmPtr != -2)
            sleep(0.1);

        printf("Finding Average\n");
        double sum = 0;
        for (int i = 1; i < size + 1; i++)
            sum += *(shmPtr + i);

        *(shmPtr + size + 2) = sum / size;
        shmdt(shmPtr);
    }
}