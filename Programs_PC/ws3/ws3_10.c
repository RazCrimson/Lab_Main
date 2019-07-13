#include <stdio.h>

int main()
{
	int i, Val=0, Small,Large,Small_loop,Large_loop;
	printf("\n ##### Finding the Largest and Smallet no. of the Sample ####\n");
	printf("Enter the Input : ");
	for (i = 1;; i++)
	{
		scanf("%d", &Val);
		if(Val  == -1)
			break;
		if (i == 1)
		{
			Small = Large = Val;
			Small_loop = Large_loop = i;
		} 
		if (Small > Val)
		{
			Small = Val;
			Small_loop = i;
		}
		if (Large < Val)
		{
			Large = Val;
			Large_loop = i;
		}
	}
	printf("\n\nThe Smallest Interger inputted is : %d and it is Data item no. #%d\n", Small,Small_loop);
	printf("\n\nThe Largest Interger inputted is : %d and it is Data item no. #%d\n", Large,Large_loop);
	return 0;
}
