#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	double a[2],b[2],c[2];
	printf("\nEnter the value of a : ");
	scanf("%f",&a[0]);
	printf("\nEnter the value of b : ");
	scanf("%f",&b[0]);
	printf("\nEnter the value of A : ");
	scanf("%f",&a[1]);
	b[1]=asin(b[0]*sin(a[1])/a[0]);
	c[1]=180-(a[1]+b[1]);
	c[0]=pow(a[0]*a[0]+b[0]*b[0]-2*a[0]*b[0]*cos(c[1]),0.5);
	printf("\nB = %.2f\nC = %.2f\nc = %.2f\nArea = %.2f\n",b[1],c[1],c[0],0.5*a[0]*b[0]*sin(c[1]));
	return 0;
}
