#include <stdio.h>
#include <stdlib.h>

void main()
{
    int *p1=malloc(sizeof(int)), *p2=malloc(sizeof(int)), *p3=malloc(s$
    printf("\nEnter nos:");
    scanf("%d%d", p1, p2);
    *p3=(*p1)+(*p2);
    printf("\nSum=%d\n", *p3);
}
