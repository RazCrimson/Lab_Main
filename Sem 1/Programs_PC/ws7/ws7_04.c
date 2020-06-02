#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char *ptr, ch, arr1[10000] = {0};
    int x = 0;
    printf("\nWorksheet 8: Program 4");
    printf("\nEnter a string1 within 999 characters  : ");
    scanf("%s", arr1);
    printf("\nEnter the character to search : ");
    scanf("%c", &ch);
    ptr = arr1;
    do
    {
        ptr = strstr(ptr, ch);
        if (ptr != NULL)
            x++;
    } while (ptr != NULL);
    printf("\nThe Character %c occurs in the string for %d times.", ch, x);
    printf("\n");
    return 0;
}