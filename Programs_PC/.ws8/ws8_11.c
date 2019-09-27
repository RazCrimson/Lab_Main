#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
    char arr[1000],ch;
    int i=0,len=0;
    long num=0;
    printf("\nWorksheet 8: Program 11");
    printf("\nEnter a string within 999 characters  : ");
    scanf("%s",arr);
    len=strlen(arr);
    for(i=0;i<len;i++)
    {
        if(isdigit(arr[i]))
        {
            num*=10;
            num+=arr[i]-48;
        }
        else
        {
            printf("\nError! The String contains non-numeric characters.");
            exit(-1);        
        }
    }
    printf("\nThe value is : %d \n",num);
    return 0;
}