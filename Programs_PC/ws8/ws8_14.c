#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char arr[1000], ch;
    int len;
    printf("\nWorksheet 8: Program 13");
    printf("\nEnter a string within 999 characters : ");
    getchar();
    scanf("%s", arr);
    printf("\nEnter the character to remove :");
    getchar();
    ch = getchar();
    len = strlen(arr);
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == ch)
        {
            for (int j = 1; j < len - 1; j++)
                arr[j] = arr[j + 1];
            i--;
            len--;
        }
    }
    printf("%s", arr);
    return 0;
}