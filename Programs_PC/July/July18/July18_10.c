#include <stdio.h>
#include <stdlib.h>

int main()
{
	float Val=0,Sum=0;
	short i;
	for(i=0;Val!=0;i++)
	{
		Sum+=Val;
		printf("\nEnter the %d th Height (in Inches) : ",i+1);
		scanf("%f",&Val);
	}
	printf("\nThe Average Height of %d Persons is %.2f\n",i-1,Sum/(i-1));
	return 0;
}
