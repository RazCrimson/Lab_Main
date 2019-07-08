#include <stdio.h>

int main()
{
	int in;
	printf("\n\t\t##### Divisibility #####");
	printf("\n\nEnter the Integer : ");
	scanf("%d",&in);
	printf("\nIs %d divisible by 5 and 6? ",in);
	if(in%5==0&&in%6==0)
		printf("True.");
	else
		printf("False.");
	printf("\nIs %d divisible by 5 or 6? ",in);
	if(in%5==0||in%6==0)
		printf("True.");
	else
		printf("False.");
	printf("\nIs %d divisible by 5 or 6, but not both? ",in);
	if((in%5==0||in%6==0)&&!(in%5==0&&in%6==0))
		printf("True.");
	else
		printf("False.");
	printf("\n");
	return 0;
}
