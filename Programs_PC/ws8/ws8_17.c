#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n=0;
    char ch;
    printf("\nWorksheet 8: Program 13")
	printf("\nEnter the Size of Array : ");
	scanf("%d",&n);
    printf("Enter the string : ");
	char *arr=(char*)malloc(sizeof(char)*(n+1);
    scanf("%[^\n]s",arr);
    printf("\nEnter the Size of Substring : ");
	scanf("%d",&n);
    char *ch=(char*)malloc(sizeof(char)*(n+1);
    printf("\nEnter the string to replace :");
    scanf("%s",ch);
    for(int cn=0;cn<strlen(ch);cn++)
    {
        for(int i=0;i<n;i++)
        {
            if(arr[i]==ch[cn])
            {
                for(int j=1;j<n-1;j++)
                    arr[j]=arr[j+1];
                i--;
                n--;
            }
        }
    }
    printf("%[^\n]s",arr);
    return 0;
}