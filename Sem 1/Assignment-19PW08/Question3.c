#include <stdio.h>
#include <stdlib.h>

int f(int n)
{
    if (n == 0)
        return 0;
    else
        return (f(n - 1) * n) + n;
}

int main()
{
    long int res = 0;
    printf("\nCalulating f(4)...");
    res = f(4);
    printf("\nThe Value of f(4) is %ld", res);
    return 0;
}