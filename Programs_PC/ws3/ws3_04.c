#include <stdio.h>

int main()
{
	char str[30];
	float Price=0,ship=0;
	short ch=0;
	printf("\n\t\t##### Cafeday Invoice #####");
	while(1)
	{
		printf("\n\nEnter the Item : ");
		fgets(str,30,stdin);
		printf("\nEnter the Price ($) : ");
		scanf("%f",&Price);
		printf("\nOvernight Delivery(1==Yes) : ");
		scanf("%hi",&ch);
		printf("\n\nInvoice:\n");
		printf("%s%.2f\n",str,Price);
		if(Price>=10.00)
			ship+=3;
		else if(Price<10.00)
			ship+=2;
		if(ch==1)
			ship+=5;
		printf("Shipping\t\t%.2f\nTotal\t\t\t%.2f",ship,ship+Price);
		printf("\n\nMore Items? -1 to stop, other to continue : ");
		scanf("%hi",&ch);
		if(ch==-1)
			break;
	}
	printf("\n");
	return 0;
}
