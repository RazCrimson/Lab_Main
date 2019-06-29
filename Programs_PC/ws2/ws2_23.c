#include <stdio.h>

int main()
{
	int sum=0;
	printf("\n ##### Sum of Even Numbers ####\n");
	for (int i = 2; i < 31; i++)
		{
			if (i % 2 == 0)
				sum+=i;
		}
		printf("\n\nThe sum of even integers from 2 to 30 is : %d", sum);
	return 0;
}