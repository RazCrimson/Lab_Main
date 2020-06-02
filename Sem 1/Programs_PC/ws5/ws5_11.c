#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	printf("\nEnter the Input : ");
	scanf("%d",&n);
	if(n&(n-1))
		printf("\nNot a power of 2\n");
	else
		printf("\nPower of 2\n");
	return 0;
}
