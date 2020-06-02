#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int Given, Guess = 0;
    srand(time(0));
    Given = rand();
    printf("\n\t\t##### Guess the value of the Random Integer #####");
    printf("\nEnter the value : ");
    scanf("%d", &Guess);
    if (Guess == Given)
        printf("\nCORRECT\n");
    else if (Guess >= Given * 10)
        printf("\nTOO HIGH\n");
    else if (Guess <= Given / 10)
        printf("\nTOO LOW\n");
    else if (abs(abs(Given) - abs(Guess)) < 5)
        printf("\nTOO CLOSE\n");
    else if ((Guess >= Given * 10) || (Given / 5 <= Guess))
        printf("\nCLOSE\n");
    return 0;
}