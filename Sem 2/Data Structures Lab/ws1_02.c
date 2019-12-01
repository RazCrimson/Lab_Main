#include <stdio.h>

int main()
{
    int a[100], i, count, min, max, sum = 0;
    float avg;
    printf("Enter the no. of elements: ");
    scanf("%d", &count);
    printf("Enter the temperatures:\n");
    for (i = 0; i < count; i++)
        scanf("%d", &a[i]);
    min = max = a[0];
    for (i = 0; i < count; i++)
    {
        sum += a[i];
        if (a[i] < min)
            min = a[i];
        else if (a[i] > max)
            max = a[i];
    }
    avg = sum / count;
    printf("The Maximum is %d\n", max);
    printf("The Minimum  is %d\n", min);
    printf("The Average is %.2f\n", avg);
    return 0;
}