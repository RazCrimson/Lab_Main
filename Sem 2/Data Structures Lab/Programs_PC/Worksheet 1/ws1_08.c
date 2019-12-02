#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char week_days[5][6] = {"Mon", "Tues", "Wed", "Thurs", "Fri"};

int max_index(int *arr, int n)
{
    int max = 0, index = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        index = i;
    }
    return index;
}

int main()
{
    int worker_count = 0, precint_count = 0;
    printf("\nEnter the Number of Workers : ");
    scanf("%d", &worker_count);
    if (worker_count <= 0)
    {
        printf("Error!!");
        exit(0);
    }
    int arr[worker_count][5];
    char worker_name[worker_count][10];
    int worker_tot[worker_count];
    int weekly_tot[5] = {0};
    memset(worker_tot, 0, sizeof(worker_tot));
    memset(worker_name, 0, sizeof(worker_name));
    for (int i = 0; i < worker_count; i++)
    {
        printf("\nEnter the name of %d Worker :", i + 1);
        scanf("%s", &worker_name[i]);
        for (int j = 0; j < 5; j++)
        {
            printf("\nEnter the Production Output for %s in %s :", &worker_name[i][0], &week_days[j][0]);
            scanf("%d", &arr[i][j]);
            worker_tot[i] += arr[i][j];
            weekly_tot[j] += arr[i][j];
        }
    }
    printf("\nWorkers\tMon\tTue\tWed\tThurs\tFri\tTotal\n");
    for (int i = 0; i < worker_count; i++)
    {
        printf("%s\t", &worker_name[i]);
        for (int j = 0; j < 5; j++)
            printf("%d\t", arr[i][j]);
        printf("%d\n",worker_tot[i]);
    }
    printf("Total:\t");
    for(int i=0;i<5;i++)
        printf("%d\t",weekly_tot[i]);
    printf("\n");
    return 0;
}