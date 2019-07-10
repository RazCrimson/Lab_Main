# include <stdio.h>

int main()
{
	float m, n, Side1, Side2, Hypotenuse;
	printf("\n ##### Using the Pythagoras Theorum ####");
	printf("\nEnter the first value : ");
	scanf("%f", &m);
	printf("\nEnter the second value : ");
	scanf("%f", &n);
	if (n > m)
	{
		Hypotenuse = n;
		n = m;
		m = Hypotenuse;
	}
	Side1 = (m * 2) - (n * 2);
	Side2 = m * n * 2;
	Hypotenuse = (m * 2) + (n * 2);
	printf("\nThe Value of Side1 : %f",Side1);
	printf("\nThe Value of Side2 : %f",Side2);
	printf("\nThe Value of Hypotenuse : %f",Hypotenuse);
	return 0;
}