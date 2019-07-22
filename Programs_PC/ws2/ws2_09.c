#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


int Encrypt()
{
	int Input, Pro[4], Remainder = 0;
	printf("\nEnter the number(only four digits) : ");
	scanf("%d", &Input);
	if (Input < 10000 && Input>0)
	{
		for (int i = 3; i >= 0; i--)
		{
			Pro[3 - i] = (Input / (pow(10, i))) - (Remainder *= 10);
			Remainder += Pro[3 - i];
			Pro[3 - i] = (Pro[3 - i] + 7) % 10;
		}
		Swap(&Pro[0], &Pro[2]);
		Swap(&Pro[1], &Pro[3]);
		Remainder = 0;
		for (int i = 3; i >= 0; i--)
		{
			Remainder += Pro[3 - i] * pow(10, i);
		}
		return Remainder;
	}
	else
	{
		printf("\n\nERROR!!");
		exit(9);
	}
}


int Decrypt()
{
	int Input, Pro[4], Remainder = 0;
	printf("\nEnter the number(only four digits) : ");
	scanf("%d", &Input);
	if (Input < 10000 && Input>0)
	{
		for (int i = 3; i >= 0; i--)
		{
			Pro[3 - i] = (Input / (pow(10, i))) - (Remainder *= 10);
			Remainder += Pro[3 - i];
			if (Pro[3 - i] >= 7)
				Pro[3 - i] -= 7;
			else if (Pro[3 - i] <= 6 && Pro[3 - i] >= 0)
				Pro[3 - i] += 3;
		}
		Swap(&Pro[0], &Pro[2]);
		Swap(&Pro[1], &Pro[3]);
		Remainder = 0;
		for (int i = 3; i >= 0; i--)
		{
			Remainder += Pro[3 - i] * pow(10, i);
		}
		return Remainder;
	}
	else
	{
		printf("\n\nERROR!!");
		exit(8);
	}
}


int main()
{
	int out;
	printf("\n\t\t ##### Basic Encryption #####");
	printf("\nEnter 1 for Encryption\nEnter 2 for Decryption\nEnter your choice : ");
	scanf("%d", &out);
	switch (out)
	{
	case 1: out = Encrypt(); break;
	case 2: out = Decrypt(); break;
	default: printf("\n\nError!!! Invalid choice.");  exit(0);
	}
	printf("\n\nThe Output value is : ");
	if (out / 1000 == 0)
		printf("0");
	if (out / 100 == 0)
		printf("0");
	if (out / 10 == 0)
		printf("0");
	printf("%d \n", out);
	return 0;
}
