#include <stdio.h>

int main()
{
    short i = 0, Pri = 0, Mac_in = -4000;
    do
    {
        Mac_in += 1000;
        Pri += 720;
        i++;
    } while ((Mac_in) < (Pri));
    printf("\nThe no of Years required is : %d\n", i);
    return 0;
}
