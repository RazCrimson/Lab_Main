#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch, n;
    unsigned short cost = 0;
    do
    {
        printf("\nEnter the Input (D-Dog / C-Cat / B-Bird / R-Reptile) : ");
        scanf("%c", &ch);
        if (ch == 'c' || ch == 'C' || ch == 'D' || ch == 'd')
        {
            printf("\nIs the Animal neutered (1-Yes/0-No) : ");
            scanf("%c", &n);
        }
        if (ch == 'c' || ch == 'C')
        {
            if (n == '1')
                cost = 240;
            else
                cost = 260;
        }
        else if (ch == 'd' || ch == 'D')
        {
            if (n == '1')
                cost = 350;
            else
                cost = 280;
        }
        else if (ch == 'b' || ch == 'B' || ch == 'r' || ch == 'R')
            cost = 0;
        else
        {
            printf("\nERROR!");
            exit(7);
        }
        printf("\nThe Insurance Fee is : %d\nEnter 1 if you want to Insure another animal : ", cost);
        scanf("%d", &cost);
    } while (cost == 1);
    return 0;
}
