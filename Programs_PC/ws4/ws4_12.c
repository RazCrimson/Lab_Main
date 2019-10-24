#include <stdio.h>
#include <stdlib.h>

int main()
{
    short i, j;
    char s[20] = "*******************";
    printf("\n");
    for (i = 10; i > 0; i--)
    {
        printf("%.*s\n", i, s);
    }
    printf("\n\n");
    for (i = 0; i < 10; i++)
    {
        for (j = i; j > 0; j--)
            printf(" ");
        printf("%.10s\n", s);
    }
    printf("\n\n");
    for (i = 0; i < 10; i++)
    {
        for (j = i; j > 0; j--)
            printf(" ");
        for (j = 10 - i; j > 0; j--)
            printf("* ");
        printf("\n");
    }
    printf("\n\n");
    for (i = 0; i < 10; i++)
    {
        for (j = i; j > 0; j--)
            printf(" ");
        printf("%.*s\n", 19 - i - i, s);
    }
    return 0;
}