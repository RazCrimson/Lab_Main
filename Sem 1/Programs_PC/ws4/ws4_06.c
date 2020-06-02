#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    unsigned short no, totcount, hit;
    char in;
    float res;
    printf("\nEnter the No. of Players : ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        hit = totcount = 0;
        printf("\nEnter the player's No. : ");
        scanf("%hu", &no);
        printf("\nH = hit, O = out, W = walk, S = sacrifice, P = hit by pitch.");
        while (1)
        {
            printf("\nEnter the Input : ");
            getchar();
            scanf("%c", &in);
            switch (in)
            {
            case 'H':
                hit++;
            case 'O':
                totcount++;
            case 'W':
            case 'S':
            case 'P':
                continue;
            }
            break;
        }
        res = (hit - 0.0) / totcount;
        if ((res * 1000) - ((int)(res * 1000)) >= 0.5)
            res = ((int)(res * 1000) + 1) / 1000;
        printf("\n\nPlayer %d's Average : %.3f", no, res);
    }
    return 0;
}