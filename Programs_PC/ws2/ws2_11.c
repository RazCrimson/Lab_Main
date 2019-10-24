#include <stdio.h>
#include <stdlib.h>

short date(int d, int m, int leap_yr)
{
    short res = 0;
    int Days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    Days[1] += leap_yr;
    for (int i = 0; m > i + 1; i++)
    {
        res += Days[i];
    }
    res += d;
    return res;
}

int main()
{
    short d, y, m, res;
    printf("\n\t\t\t ##### Finding the No.of Days #####");
    printf("\n\nEnter the Year : ");
    scanf("%hu", &y);
    printf("\nEnter the Month (1-12) : ");
    scanf("%hu", &m);
    printf("\nEnter the Date : ");
    scanf("%hu", &d);
    if (y <= 0 || m <= 0 || d <= 0)
    {
        printf("\n\nERROR!");
        exit(7);
    }
    if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
        res = date(d, m, 1);
    else
        res = date(d, m, 0);
    printf("\n\nThe given day is day %d of the year. ", res);
    printf("\n");
    return 0;
}
