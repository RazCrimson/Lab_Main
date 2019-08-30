#include <stdio.h>

int main()
{
    int n;
    printf("\nEnter the Input : ");
    scanf("%d",&n);
    printf("\nBefore Changing : ");
	for(int i=31;i>=0;i--)
		printf("%d",(n>>i)&1);
    if(n&1==1)
        n=n&~1;
    printf("\nAfter Changing : ");
	for(int i=31;i>=0;i--)
		printf("%d",(n>>i)&1);
    return 0;

}
