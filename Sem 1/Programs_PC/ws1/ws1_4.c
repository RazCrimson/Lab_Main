#include <stdio.h>

int main()
{
	int far;
	float cel;
	printf("\t\t ##### Temperature Calculation #####");
	printf("\nEnter the Temperature in Fahrenheit : ");
	scanf("%d",&far);
	cel=((0.5555*far)-32);
	printf("n\nTemperature in Celsius : %f ",cel);
	printf("\n");
	return 0;
}





