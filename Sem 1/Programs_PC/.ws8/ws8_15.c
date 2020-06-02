#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,n = 0, len=0;
    char arr[1000]={0},sub[1000]={0};
    printf("\nWorksheet 8: Program 14");
    printf("Enter the string : ");
    scanf("%[^\n]s", arr);
    printf("Enter the substring : ");
    getchar();
    scanf("%[^\n]s", sub);
    if (strlen(sub) >= strlen(arr))
    {
        printf("\nERROR!! the length of substring is largeer that main string.");
        exit(-1);
    }

    len = strlen(arr) - strlen(sub);
    for (i = 0, j = 0; i < len; i++)
    {
        for (j = 0; j < strlen(sub); j++)
            if (arr[j+i] != sub[j])
                break;
        if (j == strlen(sub))
        {
            printf("\nThe Substring occcurs in the %d th index ", i);
            break;
        }
    }
    if(i==len)
        printf("\nThe Substring dosent occcur. ");

    return 0;
}