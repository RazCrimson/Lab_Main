#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n=0;
    char ch;
    printf("\nWorksheet 8: Program 14");
	printf("\nEnter the Size of String : ");
	scanf("%d",&n);
    printf("Enter the string : ");
	char *arr=(char*)malloc(sizeof(char)*(n+1);
    scanf("%[^\n]s",arr);
    printf("\nEnter the Size of Substring : ");
	scanf("%d",&n);
    printf("Enter the substring : ");
	char *sub=(char*)malloc(sizeof(char)*(n+1);
    scanf("%[^\n]s",sub);
    if(strlen(sub)>=strlen(arr))
    {
        printf("\nERROR!! the length of substring is largeer that main string.");
        exit(-1);
    }
    len=strlen(arr)-strlen(sub);
    for(int i=0,j=0;i<len;i++)
    {
        for(j=0;j<n;j++)
            if(arr[j+i]!=sub[j+i])
                break;
        if(j==n)
        {
            printf("\nThe Substring occcurs in the %d th index ",j-1);
            break;
        }
    }
    return 0;
}