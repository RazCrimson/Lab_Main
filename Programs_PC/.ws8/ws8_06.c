#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main()
{
    char arr[1000];
    int i=0,len=0;
    printf("\nWorksheet 8: Program 6");
    printf("\nEnter a string within 999 characters  : ");
    scanf("%s",arr);
    len=strlen(arr);
    for(int i=0;i<(len/2);i++)
    {
        char temp=arr[i];
        arr[i]=arr[len-i-1];
        arr[len-i-1]=temp;
    }
    for(i=0;i<len;i++)
        printf("%c",arr[i]);
    printf("\n");
    return 0;
}
