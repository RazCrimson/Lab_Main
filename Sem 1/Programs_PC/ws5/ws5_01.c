#include <stdio.h>


int main()
{
	int a,b;
	printf("\nEnter the Input : ");
	scanf("%d%d",&a,&b);
	printf("\n\nBitwise-AND : %d\nBitwise-OR : %d\nBitwise-XOR : %d\n",a&b,a|b,a^b);
	printf("\nBitwise Left shift for a and b : ");
	for(int i=31;i>=0;i--)
		printf("%d",(a>>i)&1);
	a=a<<1;
	printf("\nAfter Shift : ");
	for(int i=31;i>=0;i--)
		printf("%d",(a>>i)&1);
	print("\n");
	for(int i=31;i>=0;i--)
		printf("%d",(b>>i)&1);
	b=b<<1;
	printf("\nAfter Shift : ");
	for(int i=31;i>=0;i--)
		printf("%d",(b>>i)&1);
	print("\n");
	printf("\nBitwise NOT for a and b : ");
	for(int i=31;i>=0;i--)
		printf("%d",(a>>i)&1);
	printf("\t");
	for(int i=31;i>=0;i--)
		printf("%d",(b>>i)&1);
	print("\n");
	return 0;
}
