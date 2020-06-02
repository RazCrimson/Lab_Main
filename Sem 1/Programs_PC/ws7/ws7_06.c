#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char arr1[10000] = {0};
    int x = 0, len = 0;
    printf("\nWorksheet 8: Program 4");
    printf("\nEnter a string1 within 999 characters  : ");
    scanf("%s", arr1);
    len = strlen(arr1);
    for (int i = 0; i < len; i++)
        if (arr1[i] == '.' || arr1[i] == ',' || arr1[i] == ' ')
            x++;
    printf("\nTH no. of words in the string is %d", x);
    printf("\n");
    return 0;
}