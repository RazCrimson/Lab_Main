#include <stdio.h>

int main()
{
	float n;
	int ch;
	printf("\n\t\t ##### Damage Calculation #### ");
	printf("\nEnter the Richard Scale Value : ");
	scanf("%f",&n);
	if(n<7.5)
		ch=1;
	else if(n<=6.5)
		ch=2;
	else if(n<=5.5)
		ch=3;
	else if(n<=5.0)
		ch=4;
	else if(n<5.0)
		ch=5;
	switch (ch)
	{
	case 1:
		printf("\n\nCharacterization : Most Buildings Destroyed "); 
		break;
	case 2:
		printf("\n\nCharacterization : Houses and Buildings may collapse. ");
		break;
	case 3:
		printf("\n\nCharacterization : Serious Damage,wall may crack or fall ");
		break;
	case 4:
		printf("\n\nCharacterization : Some Damage. ");
		break;
	case 5:
		printf("\n\nCharacterization : Little or No damage. ");
		break;
	}
	printf("\n");
	return 0;
}



/* The problem can also be handled with Switch statement, but it is cubersome and redundant.
	The Switch version of the program is saved as ws2_12(ver2).c */
