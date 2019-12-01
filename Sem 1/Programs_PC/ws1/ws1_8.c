#include <stdio.h>

int main()
{
	int h;
	float w,s;
	printf("\t\t ##### Wage Calculation #####");
	printf("\n\nEnter the No.of hours : ");
	scanf("%d",&h);
	printf("\n\nEnter the Wage per hour : ");
	scanf("%f",&w);
	s=w*h;
	if(h>40)
	{
		s+=(h-40)*w*0.5;
	}
	printf("\n\nYour pay is Rs. %.2f / for working %d Hours",s,h);
	printf("\n");
	return 0;
}





