#include <stdio.h>
#include <math.h>

int main()
{
    float Wind_Velocity, Wind_Chill_Index, Time;
    printf("\n\t\t##### Wind Chill Index #####");
    printf("\n\nEnter the Wind Speed (in Miles per hour) : ");
    scanf("%f", &Wind_Velocity);
    printf("\nEnter the Temperature (in Fahrenheit) : ");
    scanf("%f", &Time);
    if (Wind_Velocity >= 0 && Wind_Velocity <= 4)
        Wind_Chill_Index = Time;
    else if (Wind_Velocity >= 45)
        Wind_Chill_Index = 1.6 * Time - 55;
    else
        Wind_Chill_Index = 91.4 + (91.4 - Time) * (0.0203 * Wind_Velocity - 0.304 * (pow(Wind_Velocity, 0.5)) - 0.474);
    printf("\n\nThe Wind Chill Index for the given Input is : %f", Wind_Chill_Index);
    return 0;
}
