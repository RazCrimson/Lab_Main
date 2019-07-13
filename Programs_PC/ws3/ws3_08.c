#include <stdio.h>

int main()
{
	int Input = 1,Val=0,temp=0;
	printf("\n ##### Minimun Number calculation ####\n");
	printf("Enter the Input : ");
	scanf("%d", &Input);
	if (Input >= 1)
	{
		for (int i = 0; i < Input; i++)
		{
			scanf("%d", &Val);
			if (i == 0)
				temp = Val;
			if (temp > Val)
				temp = Val;
		}
	}
	printf("\n\nThe Smallest Interger inputted is : %d\n", temp);
	return 0;
}
