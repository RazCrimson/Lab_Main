#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n1,n2,i;
	short a=0;
	printf("\nEnter the Input : ");
	scanf("%d%d",&n1,&n2);
	printf("\n");
<<<<<<< HEAD
	if((n1>>31)&&(((n1>>31)&1)^((n2>>31)&1)))
	{
		printf("%d is greater than %d\n",n2,n1);
		return 0;
	}
	else if((n2>>31)&&((n1>>31)^(n2>>31)))
	{
		printf("%d is greater than %d\n",n1,n2);
		return 0;
	}
=======
	if((n1>>31)&&((n1>>31)^(n2>>31)))
		printf("n1neg %d is greater than %d\n",n2,n1);
	else if((n2>>31)&&((n1>>31)^((n2>>31))))
		printf("%n2neg d is greater than %d\n",n1,n2);
>>>>>>> 8aaa6d0f46c6b34db17beb96a0327ffac37587a5
	else if((n2>>31)&&(n1>>31))
	{
		n1=~n1+1;
		n2=~n2+1;
		a=1;
	}
	for(i=30;i>=0;i--)
	{
		if(((n1>>i)&1)&&(((n1>>i)&1)^((n2>>i)&1)))
		{
			if(a)
			{
				n1=~n1+1;
				n2=~n2+1;
				a=0;
			}
			printf("%d is greater than %d\n",n1,n2);
			return 0;
			if(!(i+1))
				break;
		}
		else if(((n2>>i)&1)&&(((n1>>i)&1^((n2>>i)&1))
		{
			if(a)
			{
				n1=~n1+1;
				n2=~n2+1;
				a=0;
			}
			printf("%d is greater than %d\n",n2,n1);
			return 0;
			if(!(i+1))
				break;
		}
	}
	if(a)
	{
		n1=~n1+1;
		n2=~n2+1;
		a=0;
	}
	printf("%d is equal to %d\n",n1,n2);
	return 0;
}
