#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
	int arr[1000]={0};
	scanf("%[^\n]s",arr);
    for(int i=0;arr[i]!=0;i++)
    {
        if(isalpha(arr[i]))
        {
            if(arr[i]==90||arr[i]==122)
                arr[i]-=25;
            else
            {
                arr[i]++;
            }
        }
    }
    printf("%[^\0]s",arr);
    return 0;
}