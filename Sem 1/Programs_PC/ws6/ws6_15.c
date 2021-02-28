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
    int n = 0, rotate = 0;
    printf("\nEnter the Size of Array : ");
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n);
    printf("\nEnter the Elements of the Array : ");
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);
    printf("Enter the no.of times to rotate : ");
    scanf("%d", &rotate);
    if (rotate >= n)
        rotate -= n;
    for (int i = 0; i < rotate; i++)
    {
        for (int j = i; j < n - 1; j++)
            swap(arr + j, arr + j + 1);
    }
    printf("\nThe Rotated Array :\t");
    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    return 0;
}