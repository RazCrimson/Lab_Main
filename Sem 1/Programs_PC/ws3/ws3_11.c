#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    float Val, L_men = INT_MAX, H_women = 0;
    printf("\n\t\t ##### Score Calculation #####");
    printf("\nEnter the Input : ");
    for (int i = 0;; i++)
    {
        scanf("%f", &Val);
        if (Val == 0)
            break;
        if (i % 2 == 0 && L_men >= Val)
            L_men = Val;
        else if (i % 2 == 1 && H_women <= Val)
            H_women = Val;
    }
    printf("\nLowest men\'s		: %.2f\nHighest women\'s	: %.2f", L_men, H_women);
    printf("\n");
    return 0;
}