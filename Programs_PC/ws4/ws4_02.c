#include <stdio.h>
#include <stdlib.h>

int main()
{
    short i, j;
    unsigned m, n;
    printf("\n\t\t##### Printing the Multiplication Table #####");
    printf("\nEnter the value of m and n : ");
    scanf("%u%u", &m, &n);
    if (m <= 0 || n <= 0)
    {
        printf("\nERROR!!");
        exit(7);
    }
    for (i = 1; i <= n; i++)
        printf("\n%u x %u = %d", m, i, m * i);
    printf("\n");
    return 0;
}