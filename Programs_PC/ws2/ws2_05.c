#include <stdio.h>

int main()
{
	char ch[4];
	int o=0;
	float res;
	printf("\n\t\t ##### Decimal Square #####");
	printf("\nEnter the Character continuously : ");
	fgets(ch,4,stdin);
	if(ch[1]=='.')
	{
		if(ch[0]=='1'||ch[0]=='2'||ch[0]=='3'||ch[0]=='4'||ch[0]=='5'||ch[0]=='6'||ch[0]=='7'||ch[0]=='8'||ch[0]=='9'||ch[0]=='0')
		{
			if(ch[2]=='1'||ch[2]=='2'||ch[2]=='3'||ch[2]=='4'||ch[2]=='5'||ch[2]=='6'||ch[2]=='7'||ch[2]=='8'||ch[2]=='9'||ch[2]=='0')
			{
		/* error */	res=ch[0]+((ch[2]-'0')/10);
				o=1;


			}
		}
	}
	if(o==0)
		printf("\n%s is not a decimal number.",ch);
	printf("\n%f\n",res);
	return 0;
}
