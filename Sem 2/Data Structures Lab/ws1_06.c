#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0, i = 0, j = 0, number = 0;
    printf("\nEnter the value of n :");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("\nInvalid value of N!");
        exit(0);
    }
    int arr[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            arr[i][j] = 0;
    i = n / 2;
    j = n - 1;
    for (number = 1; number <= n * n;)
    {
        if (i == -1 && j == n)
        {
            i = 0;
            j = n - 2;
        }
        else
        {
            if (j == n)
                j = 0;
            if (i < 0)
                i = n - 1;
        }
        if (arr[i][j] != 0)
        {
            j -= 2;
            i++;
            continue;
        }
        else
            arr[i][j] = number++;
        i--;
        j++;
    }
    printf("The magic square is for value n = %d is :\n",n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%5d", arr[i][j]);
        printf("\n");
    }
}