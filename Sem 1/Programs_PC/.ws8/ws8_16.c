#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char arr[1000];
    int i = 0, len = 0;
    printf("\nWorksheet 8: Program 15");
    printf("\nEnter a string within 999 characters  : ");
    scanf("%s", arr);
    len = strlen(arr);
    for (i = 0; i < len; i++)
    {
        if (islower(arr[i]))
            arr[i] -= 32;
        else if (isupper(arr[i]))
            arr[i] += 32;
    }
    printf("\nThe Toggled String is : %s", arr);
    return 0;
}