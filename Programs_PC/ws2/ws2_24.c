#include <stdio.h>

int main()
{
	int sum = 0;
	long long Input;
	printf("\n ##### Sum of the Digits of the given Number ####\n");
	printf("\n\nEnter the number : ");
	scanf("%lld", &Input);
	for (; Input != 0; Input /= 10)
	{
		sum += Input - ((Input / 10) * 10);
	}
	printf("\n\nThe sum of digits of the given Number is : %d", sum);
	return 0;
}