#include <stdio.h>

int main()
{
    int a[6][6], i, j, c;
    printf("Enter the elements:\n");
    for (i = 1; i <= 5; i++)
        for (j = 1; j <= 5; j++)
            scanf("%d", &a[i][j]);
    i = 1;
    j = 1;
    printf("The searched elements are: ");
    while (a[i][j] != 10 * i + j)
    {
        c = a[i][j];
        printf("%d\t", c);
        j = c % 10;
        i = c / 10;
    }
    printf("\nThe treasure was found in %d row and %d column\n", i, j);
    return 0;
}