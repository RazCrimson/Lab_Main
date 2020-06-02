#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n1,n2;
	printf("\nEnter the Input : ");
	scanf("%d%d",&n1,&n2);
	printf("\nn1 = %d\tn2 = %d",n1,n2);
	n1=n1^n2;
	n2=n1^n2;
	n1=n1^n2;
	printf("\nn1 = %d\tn2 = %d\n",n1,n2);
	return 0;
}
