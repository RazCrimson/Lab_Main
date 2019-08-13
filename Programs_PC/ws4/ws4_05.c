#include <stdio.h>
#include <stdlib.h>

int main()
{
	unsigned n,No_of_Digits;
	printf("\n\t\t##### Printing a  Palindrome #####");
	printf("\nEnter the value of n : ");
	scanf("%u", &n);
	for (No_of_Digits = 0;; No_of_Digits++)
	{
		if (((int)(n / pow(10, No_of_Digits))) <= 0)
			break;
	}
	int* arr=(int*)malloc(sizeof(int));
	for(int i=No_of_Digits-1;i>=0;i--)
	{
		*(arr+i)=n%10;
		n/=10;
	}
	for(int i=0;i<No_of_Digits/2;i++)
	{
		re:
		if(*(arr+i)==*(arr+No_of_Digits-i-1))
			continue;
		else if(*(arr+i)>=*(arr+No_of_Digits-i-1))
			*(arr+No_of_Digits-i-1)=*(arr+i);
		else if(*(arr+i)<=*(arr+No_of_Digits-i-1))
		{
			*(arr+i)=*(arr+i)+1;
			goto re;
		}
	}
	for (int i = 0; i < No_of_Digits; i++)
	{
		printf("%d",*(arr+i));
	}
	printf("\n");
	return 0;
}