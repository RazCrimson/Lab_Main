
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int i, j, random__num, n, a[6] = {0};
    srand(time(0));
    printf("Enter the number of times to roll the die: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        random__num = rand() % 6 + 1;
        for (j = 1; j <= 6; j++)
        {
            if (random__num == j)
            {
                a[j - 1]++;
            }
        }
    }
    for (i = 1; i <= 6; i++)
        printf("\t%d", i);
    printf("\n");
    for (i = 0; i < 6; i++)
        printf("\t%d", a[i]);
    printf("\n");
    return 0;
}