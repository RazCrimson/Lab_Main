#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i,n,flg=1;
	printf("\nEnter the Input : ");
	scanf("%d",&n);
	for(i=31;i>=0;i--)
	{
		if(((n>>i)&1)&&flg)
			flg--;
		else if(((n>>i)&1)&&!flg)
		{
			flg=2;
			break;
		}
	}
	if(flg==2)
		printf("\nNot Div\n");
	else
		printf("\nDiv\n");
	return 0;
}
