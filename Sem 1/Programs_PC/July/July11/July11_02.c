#include <stdio.h>
#include <stdlib.h>

int main()
{
	int  f1,f2,hr,min;
	printf("\n\t\t##### TIme Calculation ####");
	printf("\nEnter the Start Time in(24hrs format) : ");
	scanf("%d",&f1);
	if(f1%100>=60)
	{
		printf("\nERROR!");
		exit(6);
	}
	printf("\nEnter the Duration : ");
	scanf("%d",&f2);
	if(f2%100>=60)
	{
		printf("\nERROR!");
		exit(6);
	}
	min=(f1%100)+(f2%100);
	hr=(f1/100)+(f2/100)+(min/60);
	if(hr>=24)
		hr-=24;
	hr*=100;
	hr+=min;
	printf("\n\nThe End Time is %d",hr);
	printf("\n");
	return 0;
}
