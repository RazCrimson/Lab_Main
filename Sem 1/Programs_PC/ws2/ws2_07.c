#include <stdio.h>

int main()
{
    char grade;
    int points;
    printf("\n\t\t ##### Grade Calulation #####");
    printf("\nEnter the Grade : ");
    scanf("%c", grade);
    switch (grade)
    {
    case 'a':
    case 'A':
        points = 4;
        break;
    case 'b':
    case 'B':
        points = 3;
        break;
    case 'c':
    case 'C':
        points = 2;
        break;
    case 'd':
    case 'D':
        points = 1;
        break;
    default:
        points = 0;
    }
    printf("\n\nThe points Assigned is : ", points);
    return 0;
}
