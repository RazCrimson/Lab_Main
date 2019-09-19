#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char arr[1000],ch;
    int i=0,len=0;
    printf("\nWorksheet 8: Program 7");
    printf("\nEnter a string within 999 characters  : ");
    scanf("%s",arr);
    printf("\nEnter the Character to find  : ");
    scanf("%c",&ch);
    len=strlen(arr);
    for(i=0;i<len;i++)
        if(arr[i]==ch)
            break;
    if(i==len)
        printf("\nThe character is not found in the string!")    ;
    else
    {
            printf("The character is found in the %dth index of the array",i-1);
    }
    return 0;
}
    