#include <stdio.h>
#include <stdlib.h>

int main()
{
	while(1)
	{
		int tp,ini,curr;
		float price,cost[3][2]={.25,.37,.5,.63,.65,.75};
		char name[30],ch;
		printf("\n\t\t#####Tamilnadu Electricity Board #####");
		printf("\n\t\t     ---------------------------");
		printf("\nEnter the customer name : ");
		scanf("%s",name);
		printf("\nUser type:\n1.Domestic User\n2.Office\n3.Factory\nPlease Enter user type(1/2/3 or D/O/F) : ");
		getchar();
		ch=getchar();
		if(ch=='1'||ch=='D'||ch=='d')
			tp=1;
		else if(ch=='2'||ch=='O'||ch=='o')
			tp=2;
		else if(ch=='3'||ch=='F'||ch=='f')
			tp=3;
		else
		{
			printf("\nERROR!");
				exit(6);
		}
		printf("\nEnter the initial meter reading : ");
		scanf("%d",&ini);
		printf("\nEnter the current meter reading : ");
		scanf("%d",&curr);
		ini=curr-ini;
		switch(tp)
		{
			case 1:
				if(ini>500)
				{
					price=500*cost[tp-1][0];
					ini-=500;
					price+=ini*cost[tp-1][1];
				}
				else
					price=ini*cost[tp-1][0];
				break;
			case 2:
				if(ini>1000)
				{
					price=1000*cost[tp-1][0];
					ini-=1000;
					price+=ini*cost[tp-1][1];
				}
				else
					price=ini*cost[tp-1][0];
				break;
			case 3:
				if(ini>1500)
				{
					price=1500*cost[tp-1][0];
					ini-=1500;
					price+=ini*cost[tp-1][1];
				}
				else
					price=ini*cost[tp-1][0];
				break;
			default:
				printf("\nERROR!!");
				exit(6);
		}
		printf("\n\nThe Price is %.2f",price);
		printf("\n\nEnter n to stop repeating the operation : ");
		getchar();
		ch=getchar();
		if(ch=='n')
			break;
	}
	printf("\n");
	return 0;
}
