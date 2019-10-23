#include <stdio.h>

int main()
{
    int a[5][5], i, j, k, l, m = 0;
    printf("Enter the elements of the array:\n");
    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            scanf("%d", &a[i][j]);
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            l = 0;
            for (k = 0; k < 5; k++)
            {
                if (a[i][j] < a[i][k] || a[i][j] > a[k][j])
                    l = 1;
            }
            if (l == 0)
            {
                printf("The saddle point is %d in (%d,%d)\n", a[i][j], i, j);
                m = 1;
            }
        }
    }
    if (m == 0)
    {
        printf("No saddle point\n");
    }
    return 0;
}