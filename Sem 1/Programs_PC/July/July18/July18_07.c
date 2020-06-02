#include <stdio.h>
#include <stdlib.h>

int main()
{
	unsigned int n;
	long fact=1;
	printf("\nEnter the value of n : ");
	scanf("%u",&n);
	printf("\nThe Factorial of %d is ",n);
	for(;n>0;n--)
		fact*=n;
	printf("%ld\n",fact);
	return 0;
}
