#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i, j, n = 0, len = 0;
    char arr[1000] = {0}, word[1000] = {0};
    printf("\nWorksheet 8: Program 14");
    printf("Enter the string : ");
    scanf("%[^\n]s", arr);
    printf("Enter the substring : ");
    getchar();
    scanf("%[^\n]s", word);
    if (strlen(word) >= strlen(arr))
    {
        printf("\nERROR!! the length of substring is largeer that main string.");
        exit(-1);
    }
    len = strlen(arr) - strlen(word);
    n = strlen(word);
    for (i = 0, j = 0; i < len; i++)
    {
        for (j = 0; j < n; j++)
            if (arr[j + i] != word[j])
                break;
        if (j == n)
        {
            if (len > n)
            {
                for (int k = 0; k < len; k++)
                {
                    if ((k + i + -1) > len)
                        break;
                    arr[k + i] = arr[k + i + n];
                }
                i-=n;
                len -= n;
            }
            else if (len == n)
            {
                printf("The string dosent contain any other words.");
            }
        }
    }
    printf("\nThe String is ");
    for(int i=0;i<len;i++)
        printf("%c",arr[i]);
    return 0;
}