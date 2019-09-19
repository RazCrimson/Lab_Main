#include <stdio.h>
#include <string.h>


int main()
{
    char arr[1000];
    int i=0,len=0;
    printf("\nWorksheet 8: Program 1");
    printf("\nEnter a string within 999 characters  : ");
    scanf("%s",arr);
    len=strlen(arr);
    for(i=0;i<len;i++)
        printf("%c",arr[i]);
    return 0;
}