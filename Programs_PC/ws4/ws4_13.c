#include <stdio.h>

int main()
{
    int i, j;
    for (i = 1; i < 10; i++)
        printf("%d\t", i);
    for (i = 1; i < 10; i++)
    {
        printf("\n");
        for (j = 1; j < 10; j++)
            printf("%d\t", i * j);
    }
}