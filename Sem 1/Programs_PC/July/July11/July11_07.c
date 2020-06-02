#include <stdio.h>

int main()
{
    float x;
    double res;
    printf("\nEnter the value of x : ");
    scanf("%f",&x);
    printf("\nThe Value of f is %f\n",((x*x*x)-(2*x*x)+x-6.3)/((x*x)+(0.05*x)+3.14));
    return 0;
}