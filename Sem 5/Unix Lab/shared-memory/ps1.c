#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SHMSIZE 4

void die(char *message)
{
    perror(message);
    exit(1);
}

int main()
{
    int shmId1, shmId2;
    int *shmPtr1, *shmPtr2;
    key_t key1, key2;
    key1 = ftok(__FILE__, 1);

    if (fork() > 0)
    {
        shmId1 = shmget(key1, SHMSIZE, IPC_CREAT | 0666);
        if (shmId1 < 0)
            die("shmget");

        shmPtr1 = (int *)shmat(shmId1, NULL, 0);
        if (shmPtr1 == (int *)-1)
            die("shmat");

        key2 = ftok(__FILE__, 2);
        if (fork() > 0)
        {
            shmId2 = shmget(key2, SHMSIZE, IPC_CREAT | 0666);
            if (shmId2 < 0)
                die("shmget");

            shmPtr2 = (int *)shmat(shmId2, NULL, 0);
            if (shmPtr2 == (int *)-1)
                die("shmat");

            int childA = 0, childB = 0;
            while (childA < 5 && childB < 5)
            {
                *shmPtr1 = -1;
                *shmPtr2 = -1;

                while (*shmPtr1 == -1 || *shmPtr2 == -1)
                    continue;

                int choice = rand() % 2;
                printf("Choice: %d\n", choice);
                printf("Child1 score %d\n", childA);
                printf("Child2 score %d\n", childB);
                if (choice == 0)
                {
                    if (*shmPtr1 < *shmPtr2)
                        childA++;
                    else if (*shmPtr2 < *shmPtr1)
                        childB++;
                }
                else
                {
                    if (*shmPtr1 > *shmPtr2)
                        childA++;
                    else if (*shmPtr2 > *shmPtr1)
                        childB++;
                }
            }
            if (childA == 5)
                printf("Child 1 won\n");
            if (childB == 5)
                printf("Child 2 won\n");
            *shmPtr1 = -2;
            *shmPtr2 = -2;

            shmdt(shmPtr1);
            shmdt(shmPtr2);
            shmctl(shmId1, IPC_RMID, NULL);
            shmctl(shmId2, IPC_RMID, NULL);
            wait(NULL);
            wait(NULL);
        }
        else
        {
            shmId2 = shmget(key2, SHMSIZE, IPC_CREAT | 0666);
            if (shmId2 < 0)
                die("shmget");

            shmPtr2 = (int *)shmat(shmId2, NULL, 0);
            if (shmPtr2 == (int *)-1)
                die("shmat");

            srand(getpid());
            while (*shmPtr2 != -2)
            {
                if (*shmPtr2 == -1)
                    *shmPtr2 = rand();
            }
            shmdt(shmPtr2);
        }
    }
    else
    {
        shmId1 = shmget(key1, SHMSIZE, IPC_CREAT | 0666);
        if (shmId1 < 0)
            die("shmget");

        shmPtr1 = (int *)shmat(shmId1, NULL, 0);
        if (shmPtr1 == (int *)-1)
            die("shmat");

        srand(getpid());

        while (*shmPtr1 != -2)
        {
            if (*shmPtr1 == -1)
                *shmPtr1 = rand();
        }
        shmdt(shmPtr1);
    }
}