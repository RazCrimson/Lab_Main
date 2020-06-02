#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i, j, n = 0, len = 0;
    char arr[1000] = {0}, ch[1000] = {0};
    printf("\nWorksheet 8: Program 14");
    printf("\nEnter the string : ");
    scanf("%[^\n]s", arr);
    printf("Enter the substring : ");
    getchar();
    scanf("%[^\n]s", ch);
    if (strlen(ch) >= strlen(arr))
    {
        printf("\nERROR!! the length of substring is largeer that main string.");
        exit(-1);
    }
    n=strlen(arr);
    for(int cn=0;cn<strlen(ch);cn++)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == ch[cn])
            {
                for (int j = i; j < n - 1; j++)
                    arr[j] = arr[j + 1];
                i--;
                n--;
            }
        }
    }
    for(int i=0;i<n;i++)
        printf("%c",arr[i]);
    return 0;
}