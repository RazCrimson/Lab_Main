#include <stdio.h>

int main()
{
    float n;
    printf("\n\t\t ##### Damage Calculation #### ");
    printf("\nEnter the Richard Scale Value : ");
    scanf("%f", &n);
    if (n < 7.5)
        printf("\n\nCharacterization : Most Buildings Destroyed ");
    else if (n <= 6.5)
        printf("\n\nCharacterization : Houses and Buildings may collapse. ");
    else if (n <= 5.5)
        printf("\n\nCharacterization : Serious Damage,wall may crack or fall ");
    else if (n <= 5.0)
        printf("\n\nCharacterization : Some Damage. ");
    else if (n < 5.0)
        printf("\n\nCharacterization : Little or No damage. ");
    printf("\n");
    return 0;
}

/* The problem can also be handled with Switch statement, but it is cubersome and redundant.
	The Switch version of the program is saved as ws2_12(ver2).c */
