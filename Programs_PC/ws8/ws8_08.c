#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char arr[1000];
    int i = 0, len = 0;
    printf("\nWorksheet 8: Program 8");
    printf("\nEnter a string within 999 characters  : ");
    scanf("%s", arr);
    len = strlen(arr);
    for (i = 0; i < len; i++)
        if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u' || arr[i] == 'A' || arr[i] == 'E' || arr[i] == 'I' || arr[i] == 'O' || arr[i] == 'U')
            arr[i] = '*';
    for (i = 0; i < len; i++)
        if ((!(arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u' || arr[i] == 'A' || arr[i] == 'E' || arr[i] == 'I' || arr[i] == 'O' || arr[i] == 'U')) && isalpha(arr[i]))
            arr[i] = '#';
    printf("%s\n", arr);
    return 0;
}