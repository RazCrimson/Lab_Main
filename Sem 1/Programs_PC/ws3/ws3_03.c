#include <stdio.h>

int main()
{
    int Input;
    printf("\n\t\t##### Divisibility #####");
    printf("\n\nEnter the Integer : ");
    scanf("%d", &Input);
    printf("\nIs %d divisible by 5 and 6? ", Input);
    if (Input % 5 == 0 && Input % 6 == 0)
        printf("True.");
    else
        printf("False.");
    printf("\nIs %d divisible by 5 or 6? ", Input);
    if (Input % 5 == 0 || Input % 6 == 0)
        printf("True.");
    else
        printf("False.");
    printf("\nIs %d divisible by 5 or 6, but not both? ", Input);
    if ((Input % 5 == 0 || Input % 6 == 0) && !(Input % 5 == 0 && Input % 6 == 0))
        printf("True.");
    else
        printf("False.");
    printf("\n");
    return 0;
}
