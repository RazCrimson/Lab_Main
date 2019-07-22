#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,Sum=0,i;
    printf("\nEnter the Number : ");
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        if(n%i==0)
            Sum+=i;
    }
    if(Sum==n)
    {
        printf("\nThe Number is Perfect.\nIts factors are : \n");
        for(i=1;i<n;i++)
            if(n%i==0)
                printf("%d\n",i);
    }
    return 0;
}