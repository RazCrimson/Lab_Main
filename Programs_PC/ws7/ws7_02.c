#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char arr1[1000] = {0}, arr2[2000] = {0};
    int x = 0, i = 0, len = 0, len1 = 0, len2 = 0;
    printf("\nWorksheet 8: Program 4");
    printf("\nEnter a string1 within 999 characters  : ");
    scanf("%s", arr1);
    printf("\nEnter a string2 within 999 characters  : ");
    scanf("%s", arr2);
    len1 = strlen(arr1);
    len2 = strlen(arr2);
    x = len1 - len2;
    if (x > 0)
        printf("\nString1 is greater.");
    else if (x < 0)
        printf("\nString2 is greater.");
    else
    {
        len = (len1 > len2) ? len2 : len1;
        for (i = 0; i < len; i++)
        {
            if (arr1[i] > arr2[i])
            {
                printf("\nString1 is greater.");
                break;
            }
            else if (arr1[i] < arr2[i])
            {
                printf("\nString2 is greater.");
                break;
            }
        }
        if (i == len)
            printf("\nThe Strings are the same.");
    }
    printf("\n");
    return 0;
}