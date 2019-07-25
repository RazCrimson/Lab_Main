#include <stdio.h>

void print_digit(int a)
{
    if(a>=10||a<=0)
    {
        printf("\nERROR!!!");
        exit(-1);
    }
    switch(a)
    {
        case 1: printf("One "); break;
        case 2: printf("Two "); break;
        case 3: printf("Three "); break;
        case 4: printf("Four "); break;
        case 5: printf("Five "); break;
        case 6: printf("Six "); break;
        case 7: printf("Seven "); break;
        case 8: printf("Eight "); break;
        case 9: printf("Nine "); break;
    }
}



int main()
{
    long Input;
    short No_of_Digits;
    printf("\nEnter the Input : ")
    scanf("%ld", &Input);
    if(Input==0)
        printf("\nZero.");
    for (No_of_Digits = 0;; No_of_Digits++)
	{
		if (((int)(Input / pow(10, No_of_Digits))) <= 0)
			break;
	}
   while(Input>0)
   {
        if(No_of_Digits>2)
        {
            
        }
    else if()
}