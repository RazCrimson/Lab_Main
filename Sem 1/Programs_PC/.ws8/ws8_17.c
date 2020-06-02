#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main()
{
	int n=0,len=0;
    char arr[1000],ch[1000];
    printf("\nWorksheet 8: Program 16");
    printf("Enter the string : ");
    scanf("%s",arr);
    printf("Enter the substring : ");
    scanf("%[^\n]s",ch);
    for(int cn=0;cn<strlen(arr);cn++)
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