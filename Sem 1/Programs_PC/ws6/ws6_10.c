#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}

int main()
{
    int n = 0, count = 0;
    printf("\nEnter the Size of Array : ");
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
        if (arr[i] < 0)
            count++;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] < 0 && count-- > 0)
        {
            for (int j = i; j < n - 1; j++)
                swap(arr + j, arr + j + 1);
            i--;
        }
    }
    printf("\nThe Ordered Array :\t");
    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    return 0;
}