#include<stdio.h>

void main()
{
	int m=29;
	printf("\nm=%d, &m=%x", m, &m);
	int *ab=&m;
	printf("\n&ab(pointer)=%x, *ab=%d", &ab, *ab);
	m=34;
	printf("\n&ab(pointer)=%x, ab=%d", &ab, *ab);
	*ab=7;
	printf("\nm=%d, &m=%x\n", m, &m);

}





