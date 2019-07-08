#include <stdio.h>
#include <math.h>

int main()
{
	float v,wci,t;
	printf("\n\t\t##### Wind Chill Index #####");
	printf("\n\nEnter the Wind Speed (in Miles per hour) : ");
	scanf("%f",&v);
	printf("\nEnter the Temperature (in Fahrenheit) : ");
	scanf("%f",&t);
	if(v>=0&&v<=4)
		wci=t;
	else if(v>=45)
		wci=1.6*t-55;
	else 
		wci=91.4+(91.4-t)*(0.0203*v-0.304*(pow(v,0.5))-0.474);
	printf("\n\nThe Wind Chill Index for the given Input is : %f",wci);
	return 0;
}
