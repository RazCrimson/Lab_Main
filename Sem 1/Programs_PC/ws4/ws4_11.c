#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x;
    int y;
    for (y = 1; y <= 6; y++)
    {
        printf("\n\nWhen y = %d", y);
        for (x = 5.5; x <= 12.5; x = x + 0.5)
            printf("\n\tWhen x = %.1f i = %.2f", x, 2 + y + 0.5 * x);
    }
    printf("\n");
    return 0;
}
