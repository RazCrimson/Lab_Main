#include <stdio.h>

int main()
{
    float a, b, c;
    printf("\n ##### Finding the Type of Triangle ####\n");
    printf("Enter the length of First side : ");
    scanf("%f", &a);
    printf("Enter the length of Second side : ");
    scanf("%f", &b);
    printf("Enter the length of Third side : ");
    scanf("%f", &c);
    if (a == b && a == c)
        printf("\nEquilateral Tringle.\n");
    else if (a == b || b == c || a == c)
        printf("\nIsoceles Tringle.\n");
    else
        printf("\nNeither a Equilateral Tringle nor a Isoceles Triangle.\n");
    return 0;
}
