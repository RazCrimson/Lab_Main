#include <stdio.h>
#include <limits.h>
#include <stdlib.h>


int main()
{
    int n=0;
    scanf("%d",&n);
    int *arr=(int*) malloc(sizeof(int)*n);
    for(int i=0;i<=n-1;i++)
    {
        scanf("%d",(arr+i));       
    }
    for(int j=1;;j++)
    {   
        int flg=0;
        for(int i=0;i<n-1;i++)
        {
            if(a[i]==j)
            {
                flg=1;
                break;
            }      
        }
        if(flg==0)
        {   
            printf("%d",j);
            break;
        }   
    }
    return 0;

}