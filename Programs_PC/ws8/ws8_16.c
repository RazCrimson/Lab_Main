#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n=0,len=0;
    char ch,arr[1000],word[1000];
    printf("\nWorksheet 8: Program 16");
    printf("Enter the string : ");
    scanf("%s",arr);
    printf("Enter the substring : ");
    scanf("%s",word);
    if(strlen(word)>=strlen(arr))
    {
        printf("\nERROR!! the length of substring is largeer that main string.");
        exit(-1);
    }
    len=strlen(arr)-strlen(word);
    for(int i=0,j=0;i<len;i++)
    {
        for(j=0;j<n;j++)
            if(arr[j+i]!=word[j])
                break;
        if(j==n)
        {
            if(len>n)
            {
                for(int k=i-n;k<n;k++)
                {
                    if((k+n)>len)
                        break;
                    arr[k]=arr[k+n];
                }
                len-=n;
                i-=n;
            }
            else if(len==n)
            {
                printf("The string dosent contain anyother words.");
            }
            
        }
    }
    printf("\nThe String is ");
    for(int i=0;i<len;i++)
        printf("%c",arr[i]);
    return 0;
}