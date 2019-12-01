#include <stdio.h>
#include <stdlib.h>

int main()
{
    short t, n, i;
    printf("\nCalendar of a specific month will be shown.\nInput figure among following figures.\n0:Sun, 1:Mon, 2:Tue, 3:Wed, 4:Thu, 5:Fri, 6:Sat\nWhich day of the week does the month start?");
    scanf("%hu", &t);
    if (t > 6 || t < 0)
    {
        printf("\nERROR!!!");
        exit(-1);
    }
    printf("\nHow many days does the month have?");
    scanf("%hu", &n);
    if (n > 31 || n < 0)
    {
        printf("\nERROR!!!");
        exit(-1);
    }
    printf("\n\nSu\tMo\tTu\tWe\tTh\tFr\tSa\n");
    for (i = 0; i < t; i++)
        printf("\t");
    for (i = 1; i <= n; i++)
    {
        printf("%d\t", i);
        if ((i + t) % 7 == 0)
            printf("\n");
    }
    return 0;
}