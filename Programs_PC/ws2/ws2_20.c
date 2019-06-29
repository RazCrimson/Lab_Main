#include <stdio.h>

int main()
{
	int Input = 0, Val, Sum = 0;
	printf("\n ##### Sum calculation ####\n");
	printf("Enter the Input : ");
	scanf_s("%d", &Input);
	for (int i = 0; i < Input; i++)
	{
		scanf_s("%d", &Val);
		Sum += Val;
	}
	printf("\nThe Sum Value is %d", Sum);
	return 0;
}