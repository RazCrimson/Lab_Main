#include <stdio.h>


int main()
{
	int a,b;
	printf("\nEnter the Input : ");
	scanf("%d%d",&a,&b);
	printf("\n\nBitwise-AND : %d\nBitwise-OR : %d\nBitwise-XOR : %d\n",a&b,a|b,a^b);
	return 0;
}
