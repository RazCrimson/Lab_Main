#include <stdio.h>

int main()
{
    int i, j, a[5][4], b[4], total = 0, sum[4] = {0}, m = 0, k, l;
    float per[4];
    printf("Enter the voting details:\n");
    for (j = 0; j < 4; j++)
    {
        printf("Enter the votes of candidate %c in each precinct\n", 65 + j);
        for (i = 0; i < 5; i++)
        {
            scanf("%d", &a[i][j]);
            total += a[i][j];
            sum[j] += a[i][j];
        }
    }
    printf("The table is:\nPrecinct");
    for (i = 0; i < 4; i++)
    {
        printf("\t%c", 65 + i);
    }
    printf("\n");
    for (i = 0; i < 5; i++)
    {
        printf("%d\t\t", i + 1);
        for (j = 0; j < 4; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < 4; i++)
    {
        per[i] = (float)(sum[i] * 100) / total;
        printf("The total number of votes by candidate %c is %d and it is %.2f%%\n", i + 65, sum[i], per[i]);
    }
    for (i = 0; i < 4; i++)
    {
        if (per[i] > 50)
        {
            printf("The winner is candidate %c\n", i + 65);
            m = 1;
        }
    }
    if (m == 0)
    {
        printf("There are no winners\n");
        for (i = 0; i < 4; i++)
        {
            b[i] = sum[i];
        }
        for (i = 0; i < 3; i++)
        {
            for (j = i + 1; j < 4; j++)
            {
                if (b[i] > b[j])
                {
                    b[i] = b[i] ^ b[j];
                    b[j] = b[i] ^ b[j];
                    b[i] = b[i] ^ b[j];
                }
            }
        }
        for (i = 0; i < 4; i++)
        {
            if (sum[i] == b[2])
            {
                k = i;
                break;
            }
        }
        for (j = 0; j < 4; j++)
        {
            if (sum[j] == b[3] && j != k)
            {
                l = j;
                break;
            }
        }
        printf("The runoff between two candidates %c and %c\n", k + 65, l + 65);
    }
    return 0;
}
