#include <stdio.h>

int main()
{
    int i, j, n, k;
    printf("Enter the no. of lines: ");
    scanf("%d", &n);
    int a[100][100] = {0};
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (j == 0 || i == j)
                a[i][j] = 1;
            else if (i > j)
                a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
        }
    }
    for (i = 0; i < n; i++)
    {
        for (k = n - i; k > 0; k--)
        {
            printf(" ");
        }
        for (j = 0; j < n; j++)
        {
            if (a[i][j] != 0)
            {
                printf("%d ", a[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}