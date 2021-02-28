#include <stdio.h>

int main()
{
    int m1, m2, n1, n2, i, j, k, a[10][10], b[10][10], sum[10][10], dif[10][10], mult[10][10] = {0};
    printf("Enter the number of rows in first array: ");
    scanf("%d", &m1);
    printf("Enter the number of columns in first array: ");
    scanf("%d", &n1);
    printf("Enter the number of rows in second array: ");
    scanf("%d", &m2);
    printf("Enter the number of columns in second array: ");
    scanf("%d", &n2);
    printf("Enter the elements of the first array:\n");
    for (i = 0; i < m1; i++)
        for (j = 0; j < n1; j++)
            scanf("%d", &a[i][j]);
    printf("Enter the elements of the second array:\n");
    for (i = 0; i < m2; i++)
        for (j = 0; j < n2; j++)
            scanf("%d", &b[i][j]);
    if (m1 == m2 && n1 == n2)
    {
        for (i = 0; i < m1; i++)
        {
            for (j = 0; j < n1; j++)
            {
                sum[i][j] = a[i][j] + b[i][j];
                dif[i][j] = a[i][j] - b[i][j];
            }
        }
        printf("The sum is:\n");
        for (i = 0; i < m1; i++)
        {
            for (j = 0; j < n1; j++)
            {
                printf("\t%d", sum[i][j]);
            }
            printf("\n");
        }
        printf("The difference is:\n");
        for (i = 0; i < m1; i++)
        {
            for (j = 0; j < n1; j++)
            {
                printf("\t%d", dif[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Cannot add or subtract both the arrays\n");
    }
    if (n1 == m2)
    {
        for (i = 0; i < m1; i++)
        {
            for (j = 0; j < n2; j++)
            {
                for (k = 0; k < n1; k++)
                {
                    mult[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        printf("The product is:\n");
        for (i = 0; i < m1; i++)
        {
            for (j = 0; j < n2; j++)
                printf("\t%d", mult[i][j]);
            printf("\n");
        }
    }
    else
        printf("Cannot multiply both the arrays\n");
    return 0;
}