#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char arr1[1000] = {0}, arr2[2000] = {0};
    int x = 0, i = 0, len = 0;
    printf("\nWorksheet 8: Program 4");
    printf("\nEnter a string1 within 999 characters  : ");
    scanf("%s", arr1);
    printf("\nEnter a string2 within 999 characters  : ");
    scanf("%s", arr2);
    printf("\nEnter the No. of Characters to be compared : ");
    scanf("%d", &len);
    x = strncmp(arr1, arr2, sizeof(char) * len);
    if (x > 0)
        printf("\nString1 is greater.");
    else if (x < 0)
        printf("\nString2 is greater.");
    else
        printf("\nThe Strings are equal,");
    return 0;
}