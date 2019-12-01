#include <stdio.h>
#include <stdlib.h>

int main()
{
	double a,b,c,d,res;
	printf("\nEnter the value of a : ");
	scanf("%f",&a);
	printf("\nEnter the value of b : ");
	scanf("%f",&b);
	printf("\nEnter the value of c : ");
	scanf("%f",&c);
	printf("\nEnter the value of d : ");
	scanf("%f",&d);
	res=((a+b)/(c-d))+((pow(a+c,0.5)*(c+b))/((a-b)*(a+c)));
	printf("\nThe Result is : %f",&res);
	return 0;
}
