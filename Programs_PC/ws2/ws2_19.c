#include <stdio.h>

long long res = 0;

long long fact(unsigned Number)
{
	if (Number == 0)
		return 1;
	else
		res = Number * fact(Number - 1);
	return res;
}

int main()
{
	int Number = 0;
	printf("\n ##### Factorial calculation ####\n");
	printf("\nEnter the number to calculate factorial (1-20) : ");
	scanf("%d", &Number);
	printf("\n\nThe Factorial of %d is %lld", Number, fact(Number));
	return 0;
}