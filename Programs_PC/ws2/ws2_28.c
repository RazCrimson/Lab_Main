#include <stdio.h>
#include <math.h>

int main()
{
	unsigned Input = 0, pl_d = 0, hot_d = 0, col_d = 0;
	float Val, avg = 0;
	printf("\n ##### Temperature Calculation ####\n");
	printf("Enter the no. of Inputs : ");
	scanf_s("%u", &Input);
	if (Input >= 1)
	{
		for (int i = 0; i < Input; i++)
		{
			scanf_s("%u", &Val);
			if (Val >= 85)
			{
				hot_d++;
				printf("Hot day  ");
			}
			else if (Val >= 60)
			{
				pl_d++;
				printf("Pleasant day  ");
			}
			else if (Val < 60)
			{
				col_d++;
				printf("Cold day  ");
			}
			else
			{
				printf("\n\nError!");
				exit(1);
			}
			avg += Val / Input;
		}
	}
	printf("\n\nThe No of Hot days : %d\nThe No of Pleasant days : %d\nThe No of Cold days : %d\n", hot_d, pl_d, col_d);
	return 0;
}