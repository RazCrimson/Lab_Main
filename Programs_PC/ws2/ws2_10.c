#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned Poll_no,odo;
    float gm,val[4][2]={3.4,4.2,0.31,0.39,0.4,0.5,0.25,0.31};
    printf("\n\t\t ##### Pollutants Emission #####");
    printf("\n\n(1) Carbon monoxide\n(2) Hydrocarbons\n(3) Nitrogen oxides\n(4) Nonmethane hydrocarbons\n");
    printf("Enter pollutant number : ");
    scanf("%u",&Poll_no);
    printf("\nEnter number of grams emitted per mile : ");
    scanf("%f",&gm);
    printf("\nEnter odometer reading : ");
    scanf("%u",&odo);
    if(Poll_no<=0||gm<=0||odo<=0)
    {
        printf("\n\nERROR!");
        exit(7);
    }
    short i=0;
    Poll_no--;
    if(odo<=50000)
    {
        if(gm>val[Poll_no][i])
            printf("\nEmissions exceed permitted level of %.2f grams/mile.",val[Poll_no][i]);
        else
            printf("\nEmission within permitted levels."); 
    }
    else if (odo<=100000)
    {
        i++;
        if(gm>val[Poll_no][i])
            printf("\nEmissions exceed permitted level of %.2f grams/mile.",val[Poll_no][i]);
        else
            printf("\nEmission within permitted levels."); 
    }
    else
        printf("\nData not Available to check emissions levels");
    return 0;
    
}