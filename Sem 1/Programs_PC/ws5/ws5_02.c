#include <stdio.h>


int main()
{
	int a;
	printf("\nEnter the Input : ");
	scanf("%d",&a);
	printf("\nBefore Shift : ");
	for(int i=31;i>=0;i--)
		printf("%d",(a>>i)&1);
	a=a<<4;
	printf("\nAfter Shift : ");
	for(int i=31;i>=0;i--)
		printf("%d",(a>>i)&1);
	print("\n");
	return 0;
}
