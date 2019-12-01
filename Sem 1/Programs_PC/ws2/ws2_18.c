#include <stdio.h>
long res = 0;

long Con_binary(int n)
{
    if (n > 1)
        Con_binary(n / 2);
    res *= 10;
    res += n % 2;
    return res;
}

int main()
{
    printf("\n ##### Displaying values in Binary, Octal & Hexa-decimal ####\n");
    printf("Decimal\t\tBinary\t\tOctal\t\tHexa-Decimal\n");
    for (int i = 1; i <= 256; i++)
    {
        printf("%d\t\t%ld\t\t%o\t\t%x\n", i, Con_binary(i), i, i);
        res = 0;
    }
    return 0;
}
