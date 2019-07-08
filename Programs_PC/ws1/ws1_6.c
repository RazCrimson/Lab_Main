#include <stdio.h>

int main()
{
	int o,n;
	printf("\t\t ##### Pricee Calculation #####");
	printf("\n\nEnter the Old Reading : ");
	scanf("%d",&o);
	printf("\n\nEnter the New Reading : ");
	scanf("%d",&n);
	printf("\n\nThe Price is : %.2f",((n-o)*7.13)+30.50);
	printf("\n");
	return 0;
}





