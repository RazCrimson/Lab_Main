#include <stdio.h>

int main()
{
	while(1)
	{
		short Input,Sum=0,Choice=0;
		printf("\n\t\t##### Integer Sum #####");
		printf("\n\nEnter the Number(1-999)  : ");
		scanf("%hi",&Input);
		printf("\nAfter Operation :\nRemainder        Num\n---------        ---");
		for(int i=1;Input>0;i++)
		{
			Sum+=Input%10;
			printf("\n%hi\t\t %hi",Choice=(Input%10),Input/10);
			Input/=10;
		}
		printf("\n\nThe Sum of digits is : %hi",Sum);
		printf("\n\nMore Items? -1 to stop, other to continue : ");
		scanf("%hi",&Choice);
		if(Choice==-1)
			break;

	}
	printf("\n");
	return 0;
}
