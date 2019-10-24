#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int No_of_Terms;
    float Term, Sum = 0;
    printf("Enter the value of x :");
    scanf("%f", &Term);
    Term = (Term - 1.0) / Term;
    printf("Enter the value of n :");
    scanf("%d", &No_of_Terms);
    if (No_of_Terms < 1)
    {
        printf("\nERROR!!");
        exit(-1);
    }
    for (int i = 1; i <= No_of_Terms; i++)
        Sum += 0.5 * pow(Term, i);
    printf("\nThe answer is %f ", Sum);
    return 0;
}