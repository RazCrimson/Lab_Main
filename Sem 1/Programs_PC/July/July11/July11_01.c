#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cmp(int ch,int ran)
{
	if(ch==ran)
		return 0;
	switch(ch)
	{
		case 0:
			if(ran==1)
				return 1;
			else if(ran==2)
				return -1;
			break;
		case 1:
			if(ran==2)
				return 1;
			else if(ran==0)
				return -1;
			break;
		case 2:
			if(ran==0)
				return 1;
			else if(ran==1)
				return -1;
			break;
		default:
			printf("\n\nERROR!");
			exit(8);
	}

}


int main()
{
	int ran,ch,win;
	srand(time(0));
	printf("\n\t\t##### Rock, Papers & Scissors #####");
	printf("\nEnter your choice(0-scissors,1-rock,2-paper) : ");
	scanf("%d",&ch);
	ran=rand()%3;
	win=cmp(ch,ran);
	printf("\n%d",win);
	if(win==1)
		printf("\nThe Computer Wins.");
	else if(win==-1)
		printf("\nThe User Wins.");
	else if(win==0)
		printf("\nThe Match is a Draw.");
	printf("\n");
	return 0;
}
