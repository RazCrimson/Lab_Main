#include <stdio.h>


int main()
{
	unsigned char x;
	int n;
	printf("\nEnter the Input of unsigned char as a interger  : ");
	scanf("%d",&x);
	printf("\nENter the Input of n : ");
	scanf("%d",&n);
	printf("\nRightmost Bit : ");
	printf("%d",x&1);
	printf("\nThree Rightmost Bit : ");
	printf("%d",(x)&111);
	printf("\nLeftmost Bit : ");
	printf("%d",(x>>31)&1);
	printf("\nThree Leftmost Bit : ");
	printf("%d",(x>>31)&111);
	printf("\nAfter Shift : ");
	for(int i=7;i>=0;i--)
		printf("%d",(x>>i)&1);
	printf("\n");
	return 0;
}
