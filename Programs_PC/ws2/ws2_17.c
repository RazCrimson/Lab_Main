#include <stdio.h>

int main()
{
	long double pi = 0;
	long int i = 1;
	printf("\n ##### Finding the value of pi ####");
	printf("\n\nNo. of terms\t\t\t\t\t  Value of pi\n");
	for (int s = 1; !(i == 149000); s *= -1, i++)
	{
		pi += s * (4.0 / (i + i - 1.0));	/*To get 3.14 we require 119 iterations*/
		printf("%d\t\t\t\t%lf\n", i, pi);		/*To get 3.141 we require 1686 iterations*/
											/*To get 3.1415 we require 10736 iterations*/
											/*To get 3.14159 we require 146063 iterations*/
	}

}
