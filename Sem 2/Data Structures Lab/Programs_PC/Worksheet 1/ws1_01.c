#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int avg(int *arr, int n)
{
    int avg = 0;
    for (int i = 0; i < n; i++)
        avg += arr[i];
    avg /= n;
    return avg;
}

double standardDeviation(int *arr, int n, int mean)
{
    double res = 0;
    for (int i = 0; i < n; i++)
        res += pow(arr[i] - mean, 2) / n;
    res = pow(res, 0.5);
    return res;
}

void print(int *arr, int n, int number)
{
    for (int i = 0; i <= n; i++)
    {
        if (arr[i] == number)
        {
            for (int i = 0; i < n; i++)
            {
                if (arr[i] > number)
                    printf("\n%d", arr[i]);
            }
            break;
        }
    }
}

int main()
{
    int n;
    double mean = 0, sd = 0;
    printf("\nEnter the no of elements : ");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("\nError invalid no of Elements.");
        exit(0);
    }
    int *arr = (int *)malloc(n * sizeof(int));
    printf("\nEnter the elements of array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);
    mean = avg(arr, n);
    sd = standardDeviation(arr, n, mean);
    printf("Mean : %lf Standard Deviation : %lf", mean, sd);
    printf("\nEnter the number : ");
    scanf("%lf", &sd);
    print(arr, n, sd);
    return 0;
}
