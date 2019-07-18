#include <stdio.h>
#include <stdlib.h>

int main()
{
	short i;
	int p;
	long res=1;
	printf("\nEnter the values of p : ");
	scanf("%d",&p);
	if(p>0)
	{
		printf("The Mersenne Number of %d is : ",p);
		for(i=1;i<=p;i++)
			res*=2;
	printf("%ld",res-1);
	}
	else
	{
		printf("\nERROR!!");
		exit(7);
	}
	printf("\n");
	return 0;
}
