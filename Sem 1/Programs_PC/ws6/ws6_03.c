#include <stdio.h>
#include <stdlib.h>

int monthdays[13]= {0,31,28,31,30,31,30,31,31,30,31,31,30},jd=0,yr,mon,d;


int check_leap(int yr)
{
	if((yr%4==0&&!(yr%100==0))||(yr%400==0))
		return 1;
	else
		return 0;
}

int Compute()
{
	printf("\nEnter the day d :");
	scanf("%d",&d);
	printf("\nEnter the month m :");
	scanf("%d",&mon);
	printf("\nEnter the year yr :");
	scanf("%d",&yr);
	if(d<=0||mon<=0||yr<0)
	{
		printf("\nERROR!!!");
		exit(-1);
	}
	jd=0;
	for(int i=1;i<mon;i++)
		jd+=monthdays[i];
	if(mon>2)
		jd+=check_leap(yr);
	jd+=d;
	printf("\nJulian Days is : %d",jd);
	return 0;
}


int Reverse_Compute()
{
	mon=1,day=0;
	printf("\nEnter the year yr :");
	scanf("%d",&yr);
	printf("\nEnter the Julian days :");
	scanf("%d",&jd);
	if(jd<0||yr<0)
	{
		printf("\nERROR!!!");
		exit(-1);
	}
	if(jd>59)
		jd-=check_leap(yr);
	for(int i=1;jd>monthdays[i];i++)
	{
		jd-=monthdays[i];
		mon++;
	}
	d=jd;
	printf("\n\nThe Date and month are : %d and %d ",d,mon);
	return 0;
}


int main()
{
	int out;
	printf("\n\t\t ##### Julian Days #####");
	printf("\nEnter 1 for Computing\nEnter 2 for Reversing\nEnter your choice : ");
	scanf("%d", &out);
	switch (out)
	{
	case 1: Compute(); break;
	case 2: Reverse_Compute(); break;
	default: printf("\n\nError!!! Invalid choice.");  exit(0);
	}
	return 0;
}
