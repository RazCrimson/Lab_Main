#include <stdio.h>

int printf_digit(int a)
{
    if(a>=10||a<=-1)
    {
        printf("\nERROR!!!");
        return(-1);
    }
    else if (a==0)
        return 0;
    if(a>=20&&a<100)
        switch(a/10)
        {
        case 2: printf("Twenty ");    break;
        case 3: printf("Thirty ");    break;
        case 4: printf("Fourty ");    break;
        case 5: printf("Fifty ");     break;
        case 6: printf("Sixty ");     break;
        case 7: printf("Seventy ");   break;
        case 8: printf("Eighty ");    break;
        case 9: printf("Ninety ");    break;
        }
    a%=10;
    if(a==11)
        printf("Eleven ");
    else if(a==12)
        printf("Twelve ");
    else if(a==13)
        printf("Thirteen ");
    else if(a==14)
        printf("Fourteen ");
    else if(a==15)
        printf("Fifteen ");
    else if(a==16)
        printf("Sixteen ");
    else if(a==17)
        printf("Seventeen ");
    else if(a==18)
        printf("Eighteen ");
    else if(a==19)
        printf("Nineteen ");
    else if(a==10)
        printf("Ten ");
    else if(a<10)
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
    short No_of_Digits,ch=0;
    printf("\nEnter the Input : ");
    scanf("%ld", &Input);
    if(Input==0)
        printf("\nZero.");
    for (No_of_Digits = 0;; No_of_Digits++)
	{
		if (((int)(Input / pow(10, No_of_Digits))) <= 0)
			break;
	}
    if(No_of_Digits>1)
        {
            switch(No_of_Digits)
            {
                case 10:print_digit(Input/pow(10,(No_of_Digits-1)));
                        printf("Billion ");
                        Input%=pow(10,No_of_Digits--);
                case 9: print_digit(Input/pow(10,(No_of_Digits-1)));
                        printf("Hundred "); 
                        ch=1;
                        if((Input%=pow(10,No_of_Digits--))>pow(10,No_of_Digits-3))
                            printf("and ");
                case 8:
                case 7: print_digit(Input/pow(10,(No_of_Digits-2)));
                        ch=1;
                        Input%=pow(10,No_of_Digits=No_of_Digits-2);
                        if(ch==1)
                        printf("Million ");
                        ch=0;
                case 6: print_digit(Input/pow(10,(No_of_Digits-1)));
                        printf("Hundred "); 
                        ch=1;
                        if((Input%=pow(10,No_of_Digits--))>pow(10,No_of_Digits-3))
                            printf("and ");
                case 5:
                case 4: print_digit(Input/pow(10,(No_of_Digits-2)));
                        ch=1;
                        Input%=pow(10,No_of_Digits=No_of_Digits-2);
                        if(ch==1)
                            printf("Thousand ");
                case 3: print_digit(Input/pow(10,(No_of_Digits-1)));
                        printf("Hundred "); 
                        if(Input%=pow(10,No_of_Digits--)>pow(10,No_of_Digits-3))
                            printf("and ");
                case 2:
                case 1: print_digit(Input/pow(10,(No_of_Digits-2)));
                        Input%=pow(10,No_of_Digits=No_of_Digits-2);
            }
            
        }
    
}