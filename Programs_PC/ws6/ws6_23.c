#include <stdio.h>
#include <stdlib.h>

int main()
{
    int day, month, year, k = 0, DayNumber = 0;

    printf("Enter the year: ");
    scanf("%d", &year);
    if (year < 0)
    {
        printf("Enter proper year!\n");
        exit(0);
    }
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        k = 1;
    printf("Enter the month : ");
    scanf("%d", &month);
    if (month < 1 || month > 12)
    {
        printf("Enter proper month!\n");
        exit(0);
    }
    printf("Enter the day: ");
    scanf("%d", &day);
    if (day < 1 || (k == 0 && day > 365) || (k == 1 && day > 366))
    {
        printf("Enter proper date!\n");
        exit(0);
    }
    DayNumber = (month - 1) * 31 + day;
    if (month > 2)
    {
        DayNumber = DayNumber - ((4 * month + 23) / 10);
        if (k == 1)
            DayNumber++;
    }
    printf("The day number is %d\n", DayNumber);
    return 0;
}