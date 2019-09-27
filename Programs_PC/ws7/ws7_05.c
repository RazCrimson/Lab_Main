#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char *ptr, ch, arr1[10000] = {0};
    int x[26] = 0;
    printf("\nWorksheet 8: Program 4");
    printf("\nEnter a string1 within 999 characters  : ");
    scanf("%s", arr1);
    for (ch = 65; ch < 91; ch++)
    {
        ptr = strupr(arr1);
        do
        {
            ptr = strstr(ptr, ch);
            if (ptr != NULL)
                x[ch - 65]++;
        } while (ptr != NULL);
    }
    print("Character\t\tOccurance");
    for (int i = 0; i < 26; i++)
        printf("%c\t\t%d", i + 65, x[i]);
    printf("\n");
    return 0;
}