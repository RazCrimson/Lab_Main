#include <stdio.h>

int main()
{
	while(1)
	{
		short in,sum=0,ch=0;
		printf("\n\t\t##### Integer Sum #####");
		printf("\n\nEnter the Number(1-999)  : ");
		scanf("%hi",&in);
		printf("\nAfter Operation :\nRemainder        Num\n---------        ---");
		for(int i=1;in>0;i++)
		{
			sum+=in%10;
			printf("\n%hi\t\t %hi",ch=(in%10),in/10);
			in/=10;
		}
		printf("\n\nThe Sum of digits is : %hi",sum);
		printf("\n\nMore Items? -1 to stop, other to continue : ");
		scanf("%hi",&ch);
		if(ch==-1)
			break;

	}
	printf("\n");
	return 0;
}
