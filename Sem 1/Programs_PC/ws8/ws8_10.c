#include <stdio.h>

void sum(int a, int b, int *c)
{
    *c = a + b;
}

void main()
{
    int a, b, c;
    printf("\nEnter nos:");
    scanf("%d%d", &a, &b);
    sum(a, b, &c);
    printf("\nSum=%d\n", c);
}
