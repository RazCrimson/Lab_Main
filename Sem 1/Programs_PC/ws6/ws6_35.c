
#include <stdio.h>

int main()
{
    int i, j;
    char s[] = "123456789";
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 4 - i; j++)
            printf(" ");
        for (j = i + 1; j <= 2 * i + 1; j++)
            printf("%c", s[j - 1]);
        for (j = j - 2; j >= i + 1; j--)
            printf("%c", s[j - 1]);
        printf("\n");
    }
    return 0;
}