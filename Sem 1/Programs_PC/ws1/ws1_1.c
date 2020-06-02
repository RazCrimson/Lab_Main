#include <stdio.h>
#include <math.h> 

int main()
{
	int p,t,ch=0;
	float r,res;
	printf("\t\t ##### Interest Calculation #####");
	printf("\n\nEnter the Principal value : ");
	scanf("%d",&p);
	printf("\nEnter the Rate of Interest(as a rational number) : ");
	scanf("%f",&r);
	printf("Enter the No. of years : ");
	scanf("%d",&t);
	printf("\nEnter 1 for Simple Interest\nEnter 2 for Compound Interest\nEnter 3 for Maturi");
	switch(ch)
	{
		case 1:
		res=p*r*t;
		printf("\nSimple Interest %f",res);
		break;
		case 2:
		res=p*(pow((1+r),t));
		printf("\nMaturity Value : %f",res);
		break;

		case 3:
		res=p*(1+(r*t));
		printf("\nCompound Interest : %f",res);
		break;

		case 0:
		printf("n\nError!!!\n ");
	}
	printf("\n");

	return 0;
}





