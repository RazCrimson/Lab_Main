#include <stdio.h>

int main()
{
	int Input,copy,test;
	printf("\n\t\t ##### Binary Checking #####");
	printf("\n\nEnter a four digit Binary Number(Ignore 0 if it is the MSB):");
	scanf("%d",&Input);
	copy=Input;
	test=Input/1000;
	if((test==0||test==1))
	{
		Input-=test*1000;
		test=Input/100;
		if((test==0||test==1))
		{
			Input-=test*100;
			test=Input/10;
			if((test==0||test==1))
			{
				Input-=test*10;
				if((Input%10==0||Input%10==1))
				{
					printf("\n%d is a Binary Number.",copy);
					test=777;
				}
			}
		}
	}
	if(test!=777)
	{
		printf("%d is not a Binary Number.\n",copy);
	}
	return 0;
}
