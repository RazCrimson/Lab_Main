#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n=0;
    char ch;
    printf("\nWorksheet 8: Program 16")
	printf("\nEnter the Size of String : ");
	scanf("%d",&n);
    printf("Enter the string : ");
	char *arr=(char*)malloc(sizeof(char)*(n+1);
    scanf("%[^\n]s",arr);
    printf("\nEnter the Size of WOrd : ");
	scanf("%d",&n);
    printf("Enter the substring : ");
	char *word=(char*)malloc(sizeof(char)*(n+1);
    scanf("%[^\n]s",word);
    if(strlen(word)>=strlen(arr))
    {
        printf("\nERROR!! the length of substring is largeer that main string.");
        exit(-1);
    }
    len=strlen(arr)-strlen(word);
    for(int i=0,j=0;i<len;i++)
    {
        for(j=0;j<n;j++)
            if(arr[j+i]!=word[j+i])
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
            }
            else if(len==n)
            {
                printf("The string dosent contain anyother words.");
            }
            
        }
    }
    printf("\nThe String is ",)
    for(int i=0;i<len;i++)
        printf("%c",arr[i])
    return 0;
}