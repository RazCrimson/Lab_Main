#include <stdio.h>
#include <string.h>

int main()
{
    char arr[1000] = "Hello";
    int i = 0, j = 0, len = 0;
    printf("\nWorksheet 8: Program 10\n");
    len = strlen(arr);
    for (i = len; i >= 0; i--)
    {
        for (j = 0; j <= i; j++)
            printf("%c", arr[j]);
        printf("\n");
    }
    return 0;
}