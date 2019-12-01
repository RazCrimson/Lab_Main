#include <stdio.h>
#include <string.h>

int main()
{
    char arr[10] = "Hello";
    int i = 0, j = 0, len = 0;
    printf("\nWorksheet 8: Program 9\n");
    len = strlen(arr);
    for (i = 0; i < len; i++)
    {
        for (j = 0; j <= i; j++)
            printf("%c", arr[j]);
        printf("\n");
    }
    return 0;
}