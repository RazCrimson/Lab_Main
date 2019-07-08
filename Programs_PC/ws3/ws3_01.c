#include <stdio.h>

int main()
{
	unsigned short ch,in,m[]={31,28,31,30,31,30,31,31,30,31,30,31};
	printf("\n\t\t##### Days in a month #####");
	printf("\n\nEnter the Month to be displayed : ");
	scanf("%hu",&in);
	if(in>0&&in<13)
	{
		if(in==2)
		{
			printf("Is the Year, a Leap Year(Enter 1 if so)  : ");
			scanf("%hu",&ch);
			if(ch==1)
				m[1]++;
		}
		switch(in--)
		{
			case 1: printf("\n\nThere are %hu days in January. ",m[in]); break;
			case 2: printf("\n\nThere are %hu days in Feburary. ",m[in]); break;
			case 3: printf("\n\nThere are %hu days in March. ",m[in]); break;
			case 4: printf("\n\nThere are %hu days in April. ",m[in]); break;
			case 5: printf("\n\nThere are %hu days in May. ",m[in]); break;
			case 6: printf("\n\nThere are %hu days in June. ",m[in]); break;
			case 7: printf("\n\nThere are %hu days in July. ",m[in]); break;
			case 8: printf("\n\nThere are %hu days in August ",m[in]); break;
			case 9: printf("\n\nThere are %hu days in September. ",m[in]); break;
			case 10: printf("\n\nThere are %hu days in October ",m[in]); break;
			case 11: printf("\n\nThere are %hu days in November. ",m[in]); break;
			case 12: printf("\n\nThere are %hu days in December. ",m[in]); break;

		}
	}
	return 0;
}
