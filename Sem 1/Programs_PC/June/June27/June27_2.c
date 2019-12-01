#include <stdio.h>
#include <math.h>

int main()
{
	int Temp,Wind_speed;
	float res;
	printf("\n\t\t ##### Wind Chill Calculation #####");
	printf("\n\nEnter the Temperature(in Fahrenheit):");
	scanf("%d",&Temp);
	printf("\n\nEnter the Wind Speed:");
	scanf("%d",&Wind_speed);
	res=35.74+0.6215*Temp+(0.4275*Temp-35.75)*(pow(Wind_speed,0.16));
	printf("\n\nThe Wind Chill is : %d\n",res);
	return 0;
}
