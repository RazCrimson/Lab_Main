#include <stdio.h>

int main()
{
	char ch1,ch2,ch3;
	int o = 0;
	float res;
	printf("\n\t\t ##### Decimal Square #####");
	printf("\nEnter the Character continuously : ");
	scanf("%c%c%c", &ch1, &ch2, &ch3);
	if (ch2 == '.')
	{
		if (ch1 == '1' || ch1 == '2' || ch1 == '3' || ch1 == '4' || ch1 == '5' || ch1 == '6' || ch1 == '7' || ch1 == '8' || ch1 == '9' || ch1 == '0')
		{
			if (ch3 == '1' || ch3 == '2' || ch3 == '3' || ch3 == '4' || ch3 == '5' || ch3 == '6' || ch3 == '7' || ch3 == '8' || ch3 == '9' || ch3 == '0')
			{
				res = (ch1 - '0') + ((ch3 - '0') / 10.0);
				o = 1;
				res *= res;
			}
		}
	}
	if (o == 0)
	{
		printf("\n%c%c%c is not a decimal number.", ch1, ch2, ch3);
		exit(-1);
	}
	printf("\n%f\n", res);
	return 0;
}
