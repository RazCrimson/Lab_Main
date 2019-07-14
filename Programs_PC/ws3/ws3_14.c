#include <stdio.h>
#include <math.h>

int main()
{
	long long Input,Revese_int=0;
	short No_of_Digits;
	printf("\nEnter the Number : ");
	scanf("%lld", &Input);
	for (No_of_Digits = 0;; No_of_Digits++)
	{
		if (((int)(Input / pow(10, No_of_Digits))) <= 0)
			break;
	}
	for (int i = No_of_Digits - 1, Remainder = 0; i >= 0; i--)
	{
		Revese_int += ((int)(Input / (pow(10, i))) - (Remainder *= 10))*pow(10,No_of_Digits-i-1);
		Remainder += ((Input / (pow(10, i))) - (Remainder *= 10));
	}
	printf("\nThe Reverse Integer is : %lld\nDouble its value is : %lld",Revese_int,Revese_int*2);
    printf("\n");
	return 0;
}