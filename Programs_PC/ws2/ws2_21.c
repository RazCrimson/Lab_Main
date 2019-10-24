#include <stdio.h>

int main()
{
    int i, Val = 0, Average = 0;
    printf("\n ##### Average calculation ####\n");
    printf("Enter the Input : ");
    for (i = 1;; i++)
    {
        scanf("%d", &Val);
        if (Val == -999)
            break;
        Average += Val;
    }
    Average /= (i - 1);
    printf("\nThe Average Value is %d", Average);
    return 0;
}