#include <stdio.h>
#include <stdlib.h>

int main()
{
    float Val, sum = 0;
    char ch;
    printf("\n\t\t ##### XYZ Bank of India #####");
    printf("\n\t\t       *****************");
    printf("\nAmount\t\tTranscation Type\n");
    while (sum > -1)
    {
    re:
        scanf("%f\t\t%c", &Val, &ch);
        if (ch == 'd' || ch == 'D')
            sum += Val;
        else if (ch == 'w' || ch == 'W')
            sum -= Val;
        else
        {
            printf("\nEnter a Proper Value!\n", Val);
            goto re;
        }
    }
    printf("\nSorry your account is in lesser the minimum balance.\nYour Current balance amount is Rs. %.2f", sum);
    printf("\n");
    return 0;
}