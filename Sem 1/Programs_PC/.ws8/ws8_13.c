#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char arr[1000], ch;
    int len;
    printf("\nWorksheet 8: Program 13");
    printf("\nEnter a string within 999 characters : ");
    getchar();
    //getchar();
    scanf("%s",arr);
    printf("\nEnter the character to replace :");
    getchar();
    ch=getchar();
    len=strlen(arr);
    for(int i=0;i<len;i++)
    {
		if(arr[i]==ch)
        {
            for(int j=i;j<len-1;j++)
                arr[j]=arr[j+1];
            i--;
            len--;
        }
    }
    for(int i=0;i<len;i++)
        printf("%c",arr[i]);
    printf("\n");
    return 0;
}