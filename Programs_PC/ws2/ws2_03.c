#include <stdio.h>
#include <stdlib.h>

int m1,d1,f; 

int date(int d,int leap_yr)
{
	int m[]={31,28,31,30,31,30,31,31,30,31,30,31};
	m[1]+=leap_yr;
	m1=1;
	for(int i=0;i<=11,d>m[i];i++)
	{
		d-=m[i];
		m1++;
	}
	d1=d;
}


int day(int j,int m,int a )
{
	int m1,a1,as,ns;
	if(m==1)
	{
		m1=13;
		a1=a-1;
	}
	else if(m==2)
	{
		m1=14;
		a1=a-1;
	}
	else
	{
		m1=m;
		a1=a;
	}
	as=a1/100;
	ns=(a1-as*100);
	f=j+ns+(ns/4)+(5*as)+(as/4)+((13*m1)/5)+1;
	f%=7;
	return f;
}



int main()
{
	int d,y;
	printf("\n\t\t\t ##### Finding the Current Date #####");
	printf("\n\nEnter the Current Year : ");
	scanf("%d",&y);
	printf("\nEnter the Number : ");
	scanf("%d",&d);
	if(y<=0||d<=0)
    {
        printf("\n\nERROR!");
        exit(7);  
    }
	if(y%400==0||(y%4==0&&y%100!=0))
	{
		y+=(d/366);
		d%=366;
		date(d,1);
	}
	else
	{
		y+=(d/365);
		d%=365;
		date(d,0);
	}
	day(d1,m1,y);
	printf("\n\n The the answer is : %d/%d/%d ",d1,m1,y);
	switch(f)
	{
		case 0: printf("Monday."); break;
		case 1: printf("Tuesday."); break;
		case 2: printf("Wednesday."); break;
		case 3: printf("Thursday."); break;
		case 4: printf("Friday."); break;
		case 5: printf("Saturday."); break;
		case 6: printf("Sunday."); break;
	}
	printf("\n");
	return 0;
}
