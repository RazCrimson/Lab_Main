#include <stdio.h>
#include <stdlib.h>

int main()
{
    float Avg;
    short n = 1;
    while (1)
    {
        unsigned ID;
        float Rate, No_of_hours, Sal = 0;
        printf("nEnter the Employee ID : ");
        scanf("%u", &ID);
        printf("\n\nEnter the No.of hours : ");
        scanf("%d", &No_of_hours);
        if (No_of_hours < 0)
        {
            printf("\nERROR!!!");
            exit(-1);
        }
        printf("\n\nEnter the Wage per hour : ");
        scanf("%f", &Rate);
        if (Rate < 0)
        {
            printf("\nERROR!!!");
            exit(-1);
        }
        Sal = No_of_hours * Rate;
        if (No_of_hours > 40)
            Sal += (No_of_hours - 40) * Rate * 0.5;
        printf("\n\n\t\t##### PAYROLL ######");
        printf("\nEmployee ID : %u\nHourly Rate : %.2f\nNumber of Hours : %.2f", ID, Rate, No_of_hours);
        printf("\nGross Salary : %.2f\nNet Salary : ", Sal, Sal * 0.03625);
        printf("\n\nAverage amout of Salary paid is : %.2f", (Avg + Sal) / n);
        n = 2;
        printf("\nEnter 0 to break the loop : ");
        scanf("%u", &ID);
        if (ID == 0)
            break;
    }
}