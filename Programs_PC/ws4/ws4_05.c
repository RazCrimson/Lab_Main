#include <stdio.h>
#include <stdlib.h>

int main()
{
	short i;
	unsigned n;
	printf("\n\t\t##### Printing a  Palindrome #####");
	printf("\nEnter the value of n : ");
	scanf("%u", &n);
	if (n <= 0 && n > 17)
	{
		printf("\nERROR!!");
		exit(7);
	}
	char str[18];
	if(n%2!=0)
		n++;
	for (i = 0; i <= n  / 2; i++)
		str[i] = str[n - i] = (48 + i + 1);
	str[n+1] = '\0';
	printf("\n%s", str);
	return 0;
}