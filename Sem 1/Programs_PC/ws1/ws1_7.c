#include <stdio.h>

int main()
{
	int i,f;
	printf("\t\t ##### Length Calculation #####");
	printf("\n\nEnter the length(in Feet and Inches) : ");
	scanf("%d",&f);
	printf(" feet, ");
	scanf("%d",&i);
	printf(" inches");
	printf("\n\nYour total length is %d inches ",((f*21)+i));
	printf("\n");
	return 0;
}





