#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,i;
	printf("\nEnter the Input : ");
	scanf("%d",&n);
	printf("\n\n");
	for(i=31;i>=0;i--)
	{
		if((n>>i)&1)
			printf("1");
		else
			printf("0");
	}
	printf("\n");
	return 0;
}
