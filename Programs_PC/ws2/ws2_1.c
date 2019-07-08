#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a,b,c,d,m,n;
	float x1,x2,s;
	printf("\n\t\t\t ##### Solving Linear Equationsn #####");
	printf("\n\nEnter the value of a : ");
	scanf("%d",&a);
	printf("\nEnter the value of b : ");
	scanf("%d",&b);
	printf("\nEnter the value of c : ");
	scanf("%d",&c);
	printf("\nEnter the value of d : ");
	scanf("%d",&d);
	printf("\nEnter the value of m : ");
	scanf("%d",&m);
	printf("\nEnter the value of n : ");
	scanf("%d",&n);
	s=(a*d-b*c);
	if(!s)
	{
		printf("\n\n!!!! Error :  ad-bc is Zero.");
		exit(0);
	}
 	x1=(m*d-b*n)/s;
 	x2=(n*a-m*c)/s;
	printf("\n\nValue of x1 is : ",x1);
	printf("\n\nValue of x2 is : ",x2);
	return 0;
}
