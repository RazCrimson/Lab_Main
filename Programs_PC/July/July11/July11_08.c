#include <stdio.h>
#include <stdlib.h>

int main()
{
	float base,h1,h2;
	printf("\n1.Area\n2.Tension\nEnter your choice : ");
	switch(getchar())
	{
	case '1' :
		printf("Enter the value of base : ");
		scanf("%f",&base);
		printf("Enter the value of Height1 : ");
		scanf("%f",&h1);
		printf("Enter the value of Height2 : ");
		scanf("%f",&h2);
		printf("\n\nThe Area is : %.2f",(base*(h1+h2))/2);
		break;
	case '2' :
		printf("Enter the value of m1 : ");
		scanf("%f",&h1);
		printf("Enter the value of m2 : ");
		scanf("%f",&h2);
		printf("Enter the value of g : ");
		scanf("%f",&base);
		printf("\n\nThe Tension is : %.2f",((2*h1*h2)/(h1+h2))*base);
		break;
	default:
		printf("\n\nERROR!");
		exit(8);
	}
	printf("\n");
	return 0;
}
