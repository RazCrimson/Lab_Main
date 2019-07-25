#include <stdio.h>

int print_digit(int Num)
{
	if (Num >= 100 || Num <= -1)
	{
		printf("\nERROR!!!");
		return(-1);
	}
	else if(Num==0)
		return 0;
	if (Num >= 20 && Num < 100)
	{	
		switch (Num / 10)
		{
		case 1: printf("Ten ");		 break;
		case 2: printf("Twenty ");	 break;
		case 3: printf("Thirty ");   break;
		case 4: printf("Fourty ");   break;
		case 5: printf("Fifty ");    break;
		case 6: printf("Sixty ");    break;
		case 7: printf("Seventy ");  break;
		case 8: printf("Eighty ");   break;
		case 9: printf("Ninety ");   break;
		}
		Num%=10;
	}
	switch (Num)
	{  
		case 11: printf("Eleven ");		break;
		case 12: printf("Twelve "); 	break;
		case 13: printf("Thirteen ");	break;
		case 14: printf("Fourteen ");	break;
		case 15: printf("Fifteen ");	break;
		case 16: printf("Sixteen ");	break;
		case 17: printf("Seventeen ");	break;
		case 18: printf("Eighteen ");	break;
		case 19: printf("Nineteen ");	break;
		case 1:  printf("One "); 		break;
		case 2:  printf("Two "); 		break;
		case 3:  printf("Three "); 		break;
		case 4:  printf("Four "); 		break;
		case 5:  printf("Five "); 		break;
		case 6:  printf("Six "); 		break;
		case 7:  printf("Seven "); 		break;
		case 8:  printf("Eight "); 		break;
		case 9:  printf("Nine "); 		break;
		}
}





int main()
{
	int Num;
	printf("\nEnter the Input : ");
	scanf("%ld", &Num);
	if(Num>100&&Num<1000)
	{
		print_digit(Num / 100);
		printf("Hundred ");
		if(Num%100!=0)
			printf("and ")
				print_digit(Num % 100);
	}
	else if(Num>0&&Num<100)
		print_digit(Num);
	else if(Num==0)
	{
		printf("Zero ");
	}
	printf("\n");
	return 0;
}