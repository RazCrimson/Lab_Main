#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int res_val(char *band)
{
    strupr(band);
    if (strcmp("BLACK", band) == 0)
        return 0;
    else if (strcmp("BROWN", band) == 0)
        return 1;
    else if (strcmp("RED", band) == 0)
        return 2;
    else if (strcmp("ORANGE", band) == 0)
        return 3;
    else if (strcmp("YELLOW", band) == 0)
        return 4;
    else if (strcmp("GREEN", band) == 0)
        return 5;
    else if (strcmp("BLUE", band) == 0)
        return 6;
    else if (strcmp("VIOLET", band) == 0)
        return 7;
    else if (strcmp("GRAY", band) == 0)
        return 8;
    else if (strcmp("WHITE", band) == 0)
        return 9;
    else
        return -1;
}

int main()
{
    while (1)
    {
        int Sum = 0, Band_val = 0;
        char arr[20];
        printf("Enter the colors of the resistor's three bands, beginning withthe band nearest the end. Type the colors in lowercase lettersonly, NO CAPS.\n");
        printf("\nBAND1=> ");
        scanf("%s", arr);
        Band_val = res_val(arr);
        if (Band_val == -1)
        {
            printf("\nPlease Enter Valid Values!!");
            goto next;
        }
        Sum += Band_val;
        Sum *= 10;
        printf("\nBAND2=> ");
        scanf("%s", arr);
        Band_val = res_val(arr);
        if (Band_val == -1)
        {
            printf("\nPlease Enter Valid Values!!");
            goto next;
        }
        Sum += Band_val;
        Sum *= 10;
        printf("\nBAND3=> ");
        scanf("%s", arr);
        Band_val = res_val(arr);
        if (Band_val == -1)
        {
            printf("\nPlease Enter Valid Values!!");
            goto next;
        }
        Sum *= pow(10, Band_val);
        printf("Resistance value: %d kilo-ohms", Sum / 10000);
    next:
        printf("\nDo you want to decode another resistor?");
        scanf("%c", &Band_val);
        if (Band_val == 'n')
            break;
        else if (Band_val == 'y')
            continue;
        printf("\nPlease Enter Valid Values");
        goto next;
    }
    return 0;
}