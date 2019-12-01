#include <stdio.h>
#include <math.h>

int main()
{
	int a,b,c;
	printf("\n\t\t ##### Roots of a Quadratic Equations #####");
	printf("\n\nEnter the value of a:");
	scanf("%d",&a);
	printf("\nEnter the value of b:");
	scanf("%d",&b);
	printf("\nEnter the value of c:");
	scanf("%d",&c);
	if(b*b-4*a*c<0)
	{
		printf("\nThe Equation has Imaginary Roots.\n");
	}
	else
	{
	float x1,x2;
	x1=(-b+pow(b*b-4*a*c,0.5))/(2*a);
	x2=(-b-pow(b*b-4*a*c,0.5))/(2*a);
	printf("\nThe Roots are: %f and %f\n",x1,x2);
	}
	return 0;
}
