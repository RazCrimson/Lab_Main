#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned short Input;
    printf("\nEnter the Input : ");
    scanf("%hu", &Input);
    if (Input >= 100 && Input <= 999)
    {
        if (Input - ((Input % 10) + ((int)(Input / 100) * 100) == ((Input % 10) + (Input / 100))))
            printf("\nThe Middle Digit is the sum of the other two digits");
        else
        {
            printf("\nThe Middle Digit is not the sum of the other two digits");
        }
    }
    else
    {
        printf("\nERROR!\nEnter a three digit number");
        exit(7);
    }
    printf("\n");
    return 0;
}