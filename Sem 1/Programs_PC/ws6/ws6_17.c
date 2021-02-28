#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int n = 0, max = INT_MIN, count = 0;
    printf("\nEnter the Size of Array : ");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("\nERROR!! Array index cant be negative.");
        exit(-1);
    }
    int *arr = (int *)malloc(sizeof(int) * n);
    printf("Enter the Elements of the array : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
        if (max < arr[i])
            max = arr[i];
    }
    for (int i = 0; i < n; i++)
        if (arr[i] == max)
            count++;
    printf("\nThe maximum number is %d and no. of occurance is %d", max, count);
    return 0;
}