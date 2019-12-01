#include <stdio.h>

int main()
{
    int Infusion_amt, Time_infusion, Rate;
    printf("\n ##### Infusion Calculation ####");
    printf("\nVolume to be infused (Infusion_amt) => ");
    scanf("%d", &Infusion_amt);
    printf("\nMinutes over which to infuse => ");
    scanf("%d", &Time_infusion);
    Rate = (Infusion_amt / Time_infusion) * 60;
    printf("\nVTBI : %d Infusion_amt", Infusion_amt);
    printf("\nRate : %d Infusion_amt/hr", Rate);
    return 0;
}