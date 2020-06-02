#include <stdio.h>
#include <stdlib.h>

long fact(int f)
{
    if (f < 0)
    {
        printf("\nERROR!!!");
        exit(-1);
    }
    else if (f == 0)
        return 1;
    long res = 1;
    for (int i = 1; i <= f; i++)
        res *= i;
    return res;
}

int bin(int m, int x)
{
    if (m < x)
        return 0;
    else if (x == 0)
        return 1;
    else
        return ((fact(m)) / (fact(x) * fact(m - x)));
}

int main()
{
    int m, x, n;
    printf("\n\t\t##### Binomial Coefficients ####");
    printf("\nEnter the no. of binomial Terms : ");
    scanf("%d", &n);
    if (n > 0)
    {
        printf("\nm\\x");
        for (int i = 0; i <= n; i++)
            printf("\t%d", i);
        printf("\n");
        for (m = 0; m <= n; m++)
        {
            printf("%d", m);
            for (x = 0; x <= m; x++)
                printf("\t%d", bin(m, x));
            printf("\n");
        }
    }
    return 0;
}
