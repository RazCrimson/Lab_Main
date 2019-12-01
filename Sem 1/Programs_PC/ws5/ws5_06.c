#include <stdio.h>


void printbin(unsigned char x)
{
    for(int i=7;i>=0;i--)
    {
        printf("%d",(x>>i)&1);
    }
}

int main()
{
	unsigned char x;
	int n;
	printf("\nEnter the Input of unsigned char as a interger  : ");
	scanf("%d",&x);
	printbin(x);
	printf("\nRightmost Bit : ");
	printbin(x&1);
	printf("\nThree Rightmost Bit : ");
	printbin(x&0x07);
	printf("\nLeftmost Bit : ");
	printbin((x>>31)&1);
	printf("\nThree Leftmost Bit : ");
	printbin(x&0xe0);
	printf("\nThree Rightmost Bits Removed :");
	printbin(x&0xf8);
	printf("\nLeftmost Bits Removed :");
	printbin(x&0x1f);
	printf("Four rightmost bits, last bit removed :");
	printbin(x&0x0e);
	return 0;
}
