#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    long sum = 0, tot = 0;
    printf("\nEnter the value of n:");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("\nError: Invalid Size");
        exit(0);
    }
    tot = n * (n + 1) / 2;
    int *arr = calloc(n - 1, sizeof(int));
    for (int i = 0; i < n - 1; i++)
    {
        printf("\nEnter the %dth element :", i + 1);
        scanf("%d", arr + i);
        sum += arr[i];
    }
    printf("\nThe missing Number is %ld", tot - sum);
    return 0;
}