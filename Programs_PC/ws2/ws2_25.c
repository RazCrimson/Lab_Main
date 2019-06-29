#include <stdio.h>

int main()
{
	int sum = 0, Digit = 0;
	long long Input;
	printf("\n ##### Sum of the Digits of the given Number ####\n");
	printf("\n\nEnter the number : ");
	scanf_s("%lld", &Input);
	printf("\nThe Digits from right are : ");
	for (; Input != 0; Input /= 10)
	{
		Digit = Input - ((Input / 10) * 10);
		printf("%d ",Digit);
		sum += Digit;
	}
	if (sum % 9 == 0)
		printf("\nThe number is divisible by 9.", Input);
	else
		printf("\nThe number is not divisible by 9.", Input);
	return 0;
}