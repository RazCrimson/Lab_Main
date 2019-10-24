#include <stdio.h>

void foo1(int xval)
{
	int x;
	x = xval;
	printf("x=%d, &x=%x", x, &x);
}

void foo2(int dummy)
{
	int y;
	printf(" y=%d &y=%x", y, &y);
}

int main()
{
	foo1(7);
	foo2(11);
	return 0;
}
