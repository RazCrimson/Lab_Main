#include <stdio.h>

int main()
{
    int f, a, j, m, m1, a1, as, ns;
    printf("\n\t\t\t ##### Finding the Current Day #####");
    printf("\n\nEnter the Current Day : ");
    scanf("%d", &j);
    printf("\nEnter the Current Month : ");
    scanf("%d", &m);
    printf("\nEnter the Current Year : ");
    scanf("%d", &a);
    if (m == 1)
    {
        m1 = 13;
        a1 = a - 1;
    }
    else if (m == 2)
    {
        m1 = 14;
        a1 = a - 1;
    }
    else
    {
        m1 = m;
        a1 = a;
    }
    as = a1 / 100;
    ns = (a1 - as * 100);
    f = j + ns + (ns / 4) + (5 * as) + (as / 4) + ((13 * m1) / 5) + 1;
    f %= 7;
    switch (f)
    {
    case 0:
        printf("\nToday is Monday.");
        break;
    case 1:
        printf("\nToday is Tuesday.");
        break;
    case 2:
        printf("\nToday is Wednesday.");
        break;
    case 3:
        printf("\nToday is Thursday.");
        break;
    case 4:
        printf("\nToday is Friday.");
        break;
    case 5:
        printf("\nToday is Saturday.");
        break;
    case 6:
        printf("\nToday is Sunday.");
        break;
    }
    printf("\n");
    return 0;
}
