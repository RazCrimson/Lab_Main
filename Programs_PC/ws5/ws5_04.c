#include <stdio.h>


int main()
{
	unsigned char x,y;
	printf("\nEnter the Input of unsigned char as a interger  : ");
	scanf("%d",&x);
	printf("\nBefore Shift : ");
	for(int i=8;i>0;i--)
		printf("%d",(x>>i)&1);
	y=~x;
	printf("\nAfter Shift : ");
	for(int i=8;i>0;i--)
		printf("%d",(y>>i)&1);
	printf("\n");
	return 0;
}
