#include <stdio.h>

int main()
{
	int h,m,s;
	printf("\t\t ##### Timee Calculation #####");
	printf("\n\nEnter the No.of Seconds : ");
	scanf("%d",&s);
	h=s/3600;
	s=s%3600;
	m=s/60;
	s=s%60;
	printf("\n\n%d Seconds gives %d Hours %d Minutes %d Seconds",((h*3600)+(m*60)+s));
	printf("\n");
	return 0;
}





