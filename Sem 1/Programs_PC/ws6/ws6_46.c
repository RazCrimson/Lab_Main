#include <stdio.h>

void main()
{
    int i, j, k, a[3][3], b[3][3], sum[3][3], dif[3][3], mult[3][3] = {0};
    printf("Enter the elements of the first array:\n");
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            scanf("%d", &a[i][j]);
    printf("Enter the elements of the second array:\n");
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            scanf("%d", &b[i][j]);
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            sum[i][j] = a[i][j] + b[i][j];
            dif[i][j] = a[i][j] - b[i][j];
            for (k = 0; k < 3; k++)
            {
                mult[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    printf("The sum is:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("\t%d", sum[i][j]);
        }
        printf("\n");
    }
    printf("The difference is:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("\t%d", dif[i][j]);
        }
        printf("\n");
    }
    printf("The product is:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("\t%d", mult[i][j]);
        }
        printf("\n");
    }
    return 0;
}