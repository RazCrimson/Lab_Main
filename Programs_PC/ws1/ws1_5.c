#include <stdio.h>

int main()
{
	int h;
	float w;
	printf("\t\t ##### Wage Calculation #####");
	printf("\n\nEnter the No.of hours : ");
	scanf("%d",&h);
	printf("\n\nEnter the Wage per hour : ");
	scanf("%f",&w);
	
	printf("\n\nYour pay is Rs. %.2f / for working %d Hours",w*h,h);
	printf("\n");
	return 0;
}





