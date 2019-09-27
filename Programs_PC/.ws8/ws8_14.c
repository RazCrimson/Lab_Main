#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n=0,len=0;
    char ch,arr[1000],sub[1000];
    printf("\nWorksheet 8: Program 16");
    printf("\nEnter the string : ");
    scanf("%s",arr);
    printf("Enter the substring : ");
    scanf("%s",sub);
    n=strlen(sub);
    if(n>=strlen(arr))
    {
        printf("\nERROR!! the length of substring is largeer that main string.");
        exit(-1);
    }
    len=strlen(arr)-n;
    for(int i=0,j=0;i<len;i++)
    {
        for(j=0;j<n;j++)
            if(arr[j+i]!=sub[j])
                break;
        if(j==n)
        {
            printf("\nThe Substring occcurs in the %d th index ",j-1);
            break;
        }
    }
    return 0;
}