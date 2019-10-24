#include <stdio.h>

int main()
{
    int x1, y1, x2, y2, x_mid, y_mid;
    float Slope_line, Slope_perpendicular_Bisector, inter;
    printf("\n ##### Finding ther Perpendicular Bisector ####");
    printf("\nEnter the x-coordinate of the first point : ");
    scanf("%d", &x1);
    printf("\nEnter the y-coordinate of the first point : ");
    scanf("%d", &y1);
    printf("\nEnter the x-coordinate of the second point : ");
    scanf("%d", &x2);
    printf("\nEnter the y-coordinate of the second point : ");
    scanf("%d", &y2);
    x_mid = (x1 + x2) / 2;
    y_mid = (y1 + y2) / 2;
    printf("\nThe First point is (%d,%d)", x1, y1);
    printf("\nThe Second point is (%d,%d)", x2, y2);
    if ((x2 - x1) != 0)
    {
        Slope_line = (y2 - y1) / (x2 - x1);
        if (Slope_line != 0)
        {
            Slope_perpendicular_Bisector = (-1 / Slope_line);
            inter = y_mid - (Slope_perpendicular_Bisector * x_mid);
            printf("\nThe Equation of the Perpendicular Bisector is y = %.2fx + %.2f", Slope_perpendicular_Bisector, inter);
        }
        else
            printf("\nThe Equation of the Perpendicular Bisector is x = %.2f", x_mid);
    }
    else
        printf("\nThe Equation of the Perpendicular Bisector is y = %.2f", y_mid);
    return 0;
}