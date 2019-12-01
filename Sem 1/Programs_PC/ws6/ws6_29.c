
#include <stdio.h>
#include <time.h>

int main()
{
    int i, a[100];
    srand(time(0));
    for (i = 0; i < 100; i++)
        a[i] = rand();
    for (i = 0; i < 50; i++)
    {
        int temp = a[100 - i];
        a[100 - i] = a[i];
        a[i] = temp;
    }
    printf("The reversed array is:\n");
    for (i = 0; i < 100; i++)
        printf("%d\t", a[i]);
    return 0;
}