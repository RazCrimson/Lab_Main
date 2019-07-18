#include <stdio.h>
#include <stdlib.h>

int main()
{
	float Val, L_men, H_women;
	printf("\n\t\t ##### Score Calculation #####");
	printf("\nEnter the Input : ");
	for (int i = 0;; i++)
	{
		scanf("%f", &Val);
		if (Val == 0)
			break;
		if (i == 0)
			L_men = Val;
		if (i == 1)
			H_women = Val;
		if (i % 2 == 0 && L_men >= Val)
			L_men = Val;
		else if (i % 2 == 1 && H_women <= Val)
			H_women = Val;
	}
	printf("\nLowest men\'s		: %.2f\nHighest women\'s	: %.2f", L_men, H_women);
	printf("\n");
	return 0;
}