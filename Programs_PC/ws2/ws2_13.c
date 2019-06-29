# include <stdio.h>
# include <math.h>

int main()
{
     float Weight_lb,Height_inches,BMI;
     printf("\n ##### BMI Calculation ####");
     printf("\nEnter the weight in pounds : ");
     scanf_s("%f",&Weight_lb);
     printf("\nEnter the height in inches : ");
     scanf_s("%f",&Height_inches);
     BMI=(703*Weight_lb)/(Height_inches*Height_inches);
     BMI=round(BMI*100)/100;
     printf("\n\nThe Body Mass Index[BMI] is : %.1f ",BMI);
     return 0;
}