#include <stdio.h>


int main()
{
	unsigned char x;
	int n;
	printf("\nEnter the Input of unsigned char as a interger  : ");
	scanf("%d",&x);
	printf("\nEnter the Input of n : ");
	scanf("%d",&n);
	printf("\nBefore Shift : ");
	for(int i=7;i>=0;i--)
		printf("%d",(x>>i)&1);
	for(int i=0;i<n;i++)
		x=(((x&1)<<7)|(x>>1));
	printf("\nAfter Shift : ");
	for(int i=7;i>=0;i--)
		printf("%d",(x>>i)&1);
	printf("\n");
	return 0;
}
