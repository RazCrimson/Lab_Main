#include <stdio.h>
#include <stdlib.h>

int main()
{
	int input,s,d;
	printf("\n\t\t ##### Card Calulation #####");
	printf("\nEnter the card No. (1-52) : ");
	scanf("%d",&input);
	if(input>52||input<1)
	{
		printf("\n\nError!!! Invalid number");
	}
	s=input/13;
	if(input==13||input==26||input==39||input==52)
		s--;
	printf("\n%d ",s);
	d=input%13;
	printf("\n%d ",d);
	printf("The given Card is ");
	switch(d)
	{
		case 1: printf("Ace "); break;
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9: 
		case 10: printf("%d ",d); break;
		case 11: printf("Jack "); break;
		case 12: printf("Queen "); break;
		case 0: printf("King "); break;
		default: printf("\n\nError!!!"); exit(0);
	}
	printf("of ");
	switch(s)
	{
		case 1: printf("Diamonds.\n");  break;
		case 2: printf("Hearts\n");     break;
		case 3: printf("Spades.\n");    break;
		case 0: printf("Clubs.\n");     break;
		default: printf("\n\nError!!!"); exit(0);
	}
	return 0;
}
