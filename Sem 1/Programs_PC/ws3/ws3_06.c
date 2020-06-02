#include <stdio.h>
#include <math.h>

int main()
{
    short Choice = 0;
    while (Choice != -1)
    {
        long Input, Remainder = 0;
        short No_of_Digits;
        printf("\n\t\t##### Integer Digits #####");
        printf("\n\nEnter an Integer Number  : ");
        scanf("%ld", &Input);
        if (Input < 0)
            Input = -Input;
        printf("\nThe Individual Digits are : ");
        for (No_of_Digits = 0;; No_of_Digits++)
        {
            if (((int)(Input / pow(10, No_of_Digits))) <= 0)
                break;
        }
        for (; No_of_Digits > 0; No_of_Digits--)
        {
            int Digit;
            printf("%d ", Digit = (Input / pow(10, No_of_Digits - 1)) - (Remainder *= 10));
            Remainder += Digit;
        }
        printf("\n\nMore Items? -1 to stop, other to continue : ");
        scanf("%hi", &Choice);
    }
    printf("\n");
    return 0;
}
