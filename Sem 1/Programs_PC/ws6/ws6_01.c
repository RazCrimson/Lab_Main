#include <stdio.h>
#include <math.h>
void main()
{
    int k, n, i, j, temp, sum1 = 0, sum2 = 0;
    float avg, sqm;
    char c, ch = 'y';
l1:
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n];
    if (n <= 0)
    {
        printf("Enter a positive number\n");
        exit(0);
    }
    printf("Enter the elements\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (a[j] < a[i])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
    do
    {
    l2:
        printf("Enter the operation to be performed:\n");
        printf("1.Average\n");
        printf("2.Median\n");
        printf("3.Range\n");
        printf("4.Standard Deviation\n");
        scanf("%d", &k);
        sum1 = 0;
        for (i = 0; i < n; i++)
            sum1 += a[i];
        avg = sum1 / n;
        switch (k)
        {
        case 1:
            printf("Average is %.2f\n", avg);
            break;
        case 2:
            printf("Median value is %d\n", a[n / 2]);
            break;
        case 3:
            printf("Range is %d\n", a[n - 1] - a[0]);
            break;
        case 4:
            for (i = 0; i < n; i++)
                sum2 += a[i] * a[i];
            sqm = sum2 / n;
            printf("Standard deviation is %f\n", sqrt(sqm - avg * avg));
            break;
        default:
            printf("Enter valid input\n");
            goto l2;
        }
        printf("Do you want to continue?(y/n) ");
        scanf("%c%c", &c, &ch);
    } while (ch == 'y' || ch == 'Y');
}