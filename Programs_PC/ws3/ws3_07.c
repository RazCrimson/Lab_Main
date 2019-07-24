#include <stdio.h>

int main()
{
	int Num;
	printf("\nEnter the Input : ");
	scanf("%ld", &Num);
	if (Num == 0)
		printf("\nZero.");
	if (Num >= 100 || Num <= -1)
	{
		printf("\nERROR!!!");
		return(-1);
	}
	else if (Num == 0)
		return 0;
	if (Num >= 20 && Num < 100)
		switch (Num / 10)
		{
		case 2: printf("Twenty ");    break;
		case 3: printf("Thirty ");    break;
		case 4: printf("Fourty ");    break;
		case 5: printf("Fifty ");     break;
		case 6: printf("Sixty ");     break;
		case 7: printf("Seventy ");   break;
		case 8: printf("Eighty ");    break;
		case 9: printf("Ninety ");    break;
		}
	Num %= 10;
	if (Num == 11)
		printf("Eleven ");
	else if (Num == 12)
		printf("Twelve ");
	else if (Num == 13)
		printf("Thirteen ");
	else if (Num == 14)
		printf("Fourteen ");
	else if (Num == 15)
		printf("Fifteen ");
	else if (Num == 16)
		printf("Sixteen ");
	else if (Num == 17)
		printf("Seventeen ");
	else if (Num == 18)
		printf("Eighteen ");
	else if (Num == 19)
		printf("Nineteen ");
	else if (Num == 10)
		printf("Ten ");
	else if (Num < 10)
		switch (Num)
		{
		case 1: printf("One "); break;
		case 2: printf("Two "); break;
		case 3: printf("Three "); break;
		case 4: printf("Four "); break;
		case 5: printf("Five "); break;
		case 6: printf("Six "); break;
		case 7: printf("Seven "); break;
		case 8: printf("Eight "); break;
		case 9: printf("Nine "); break;
		}
	return 0;
}