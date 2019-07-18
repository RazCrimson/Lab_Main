#include <stdio.h>
#include <stdlib.h>

int main()
{
	short i,j;
	for(i=3;i<=9;i++)
	{
		printf("\n\nWhen X = %d",i);
		for(j = 2;j<=4;j++)
			printf("\nWhen Y = %d,X^2 - Y^2 = %d",j,(i*i)-(j*j));
	}
	printf("\n");
	return 0;
}
