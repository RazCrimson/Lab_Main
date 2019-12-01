#include <stdio.h>

int main()
{
    int n,i;
    printf("\nEnter the Input : ");
    scanf("%d",&n);
    for(i=31;!((n>>i)&1),i>=0;i--);
    if(i<0)
        printf("\nNo bit is set.\n");
    else
        printf("\nThe %dth bit is set.\n",i);
    return 0;
    
}