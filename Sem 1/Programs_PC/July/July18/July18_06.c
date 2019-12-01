#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,sum=0;
	printf("\nEnter the value of n : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		sum+=i;
	printf("\nThe Value of Sum is : %d \n",sum);
	return 0;
}
