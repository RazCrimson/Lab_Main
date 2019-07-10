#include <stdio.h>
#include <math.h>

int main()
{
    int Input;
    float Val,Standard_Deviation=0,Sum_Squares=0,Average=0,Max_val=0,Min_val=0;
    printf("\n ##### Standard Deviation Calculation ####\n");
	printf("Enter the Input : ");
	scanf("%d", &Input);
    if (Input >= 1)
	{
		for (int i = 0; i < Input; i++)
		{
			scanf("%f", &Val);
			if (i == 0)
            	Min_val = Max_val= Val;
            if (Min_val > Val)
				Min_val = Val;
            if (Max_val < Val)
				Max_val = Val;
            Sum_Squares+=Val*Val;
            Average+=Val/Input;
		}
	}
    Standard_Deviation=pow((Sum_Squares/Input)-(Average*Average),0.5);
    printf("\n\nThe Range is from %f to %f \nThe Standard Deviation is : %f",Min_val,Max_val,Standard_Deviation);
    return 0;
}