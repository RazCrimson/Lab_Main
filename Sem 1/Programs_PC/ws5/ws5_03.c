#include <stdio.h>


int main()
{
	int a,b;
	long res=0;
	printf("\nEnter the Input : ");
	scanf("%d%d",&a,&b);
	printf("\n\nThe Number : %d\nThe power : %d",a,b);
	b=1<<b;
	for(int i=1;i<=b;i++)
		res+=a;
	printf("\nResult : %ld\n",res);
	return 0;
}
