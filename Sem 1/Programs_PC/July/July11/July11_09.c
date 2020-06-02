#include <stdio.h>

void swap_temp(int* a,int* b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void swap(int* a,int* b)
{
    *a=*a^*b;
    *b=*a^*b;
    *a=*a^*b;
}

int main()
{
    int a,b;
    printf("\n\t\t##### Swapping Numbers ####");
    printf("\nEnter the first Number : ");
	scanf("%d",&a);
	printf("\nEnter the Second Number : ");
	scanf("%d",&b);
    printf("\n1.Swap with a Termporary Variable\n2.Swap without a Temporary Variable\nEnter your choice : ");
    getchar();
    switch(getchar())
    {
        case '1': swap_temp(&a,&b); break;
        case '2': swap(&a,&b); break;
        default: printf("\nERROR!");
    }
    printf("\nThe Numbers are %d and %d respectively",a,b);
    return 0;
}