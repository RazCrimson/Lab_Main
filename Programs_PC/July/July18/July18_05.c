#include <stdio.h>
#include <stdlib.h>

int main()
{
	short i,j,l;
	for(i=1;i<=20;i++)
	{
		printf("\n\nWhen X = %d",i);
		for(j = -5;j<=5;j++)
		{
			printf("\n\n\tWhen Y = %d",j);
			for(l=3;l<=17;l++)
			printf("\n\t\tWhen Z = %d,6X^3 - 5Y^2 -4Z+2 = %d",l,(6*(i*i*i)-5*(j*j)-4*l+2));
		}
	}
	printf("\n");
	return 0;
}
