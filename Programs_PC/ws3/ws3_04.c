#include <stdio.h>

int main()
{
    char String_Input[30];
    float Cost = 0, Shipping_Fee = 0;
    short Choice = 0;
    printf("\n\t\t##### Cafeday Invoice #####");
    while (1)
    {
        printf("\n\nEnter the Item : ");
        fgets(String_Input, 30, stdin);
        printf("\nEnter the Cost ($) : ");
        scanf("%f", &Cost);
        printf("\nOvernight Delivery(1==Yes) : ");
        scanf("%hi", &Choice);
        printf("\n\nInvoice:\n");
        printf("%s%.2f\n", String_Input, Cost);
        if (Cost >= 10.00)
            Shipping_Fee += 3;
        else if (Cost < 10.00)
            Shipping_Fee += 2;
        if (Choice == 1)
            Shipping_Fee += 5;
        printf("Shipping\t\t%.2f\nTotal\t\t\t%.2f", Shipping_Fee, Shipping_Fee + Cost);
        printf("\n\nMore Items? -1 to stop, other to continue : ");
        scanf("%hi", &Choice);
        if (Choice == -1)
            break;
    }
    printf("\n");
    return 0;
}
