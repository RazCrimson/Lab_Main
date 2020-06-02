#include <stdio.h>
#include <limits.h>

int main()
{
	int a,b,ch,res;
	printf("\n\t\t##### Aritematic in Octal and Hexa decimal####\n");
	printf("Enter the value of a  : ");
	scanf("%d",&a);
	printf("\nThe Octal value of a is : %o",a);
	printf("\nThe Hexa-Decimal value of a is : %x",a);
	printf("\n\nEnter the value of b  : ");
	scanf("%d",&b);
	printf("\nThe Octal value of b is : %o",b);
	printf("\nThe Hexa-Decimal value of b is : %x",b);
	printf("\n\nEnter 1 for Addition\nEnter 2 for Subtraction\nEnter 3 for Multiplication\nEnter 4 for Division.");
	printf("\nEnter your choice : ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: printf("\n\nADDITION\n");
			res=a+b;
			printf("The Result is : %d ",res);
			printf("\nThe Octal value of a is : %o",res);
			printf("\nThe Hexa-Decimal value of a is : %x",res);
			break;

		case 2: printf("\n\nSUBTRACTION\n");
			res=a-b;
			printf("The Result is : %d ",res);
			printf("\nThe Octal value of a is : %o",res);
			printf("\nThe Hexa-Decimal value of a is : %x",res);
			break;

		case 3: printf("\n\nMULTIPLICATION\n");
			res=a*b;
			printf("The Result is : %d ",res);
			printf("\nThe Octal value of a is : %o",res);
			printf("\nThe Hexa-Decimal value of a is : %x",res);
			break;

		case 4: printf("\n\nDIVISION\n");
			res=a/b;
			printf("The Result is : %d ",res);
			printf("\nThe Octal value of a is : %o",res);
			printf("\nThe Hexa-Decimal value of a is : %x",res);
			break;

	}
	printf("\n");
	return 0;
}

