#include <stdio.h>
#include <stdlib.h>

int main()
{
	short i;
	int n,p;
	long res=1;
	printf("\nEnter the values of n and p : ");
	scanf("%d%d",&n,&p);
	if(p>0)
	{
		printf("The Value of %d^%d is : ",n,p);
		for(i=1;i<=p;i++)
			res*=n;
	printf("%ld",res);
	}
	else
	{
		printf("\nERROR!!");
		exit(7);
	}
	printf("\n");
	return 0;
}
