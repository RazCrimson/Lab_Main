#include <stdio.h>
#include <math.h>
void main()
{
    float p, c, i, n, a, mp, t, x, y, j = 0;
    printf("\n Principal:");
    scanf("%f", &p);
    printf("\n Annual interest rate:");
    scanf("%f", &t);
    printf("\n Term:");
    scanf("%f", &n);
    i = (1 / 12.0) * (t / 100);
    a = pow((1 + i), -n);
    mp = (i * p) / (1 - a);
    printf("\nMonth\t\tInterest\tPrincipal\tAmount Remaining\n");
    do
    {
        x = (9 / 1200.0) * p;
        y = mp - x;
        p = p - y;
        j++;
        printf("\n%d\t\t%.2f\t\t%.2f\t\t%.2f\n", j, x, y, p);
    } while (j < n);
    printf("\nFinal  Payment : %.2f \n", mp);
    return 0;
}
