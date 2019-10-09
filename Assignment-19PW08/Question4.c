#include <stdio.h>
#include <stdlib.h>

int sum(int n)
{
    if (n == 0)
        return 0;
    else
        return sum(n - 1) + n;
}

int main()
{
    int N = 0, Sum_recursion = 0, Sum_Loop = 0;
    printf("\nCalulating sum of N natural Numbers using recursion and Loops!\
    \nEnter the Value of N :");
    scanf("%d", &N);
    Sum_recursion = sum(N);
    for (int i = 0; i <= N; i++)
        Sum_Loop += i;
    printf("\nThe Sum of %d Natural Numbers by Recursion is %d\
    and by Loops is %d",
           N, Sum_recursion, Sum_Loop);
    return 0;
}