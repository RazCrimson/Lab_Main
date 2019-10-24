#include<stdlib.h>
#include<stdio.h>

void main()
{
        int *p1=malloc(sizeof(int)), *p2=malloc(sizeof(int));
        printf("\nEnter nos:");
        scanf("%d%d", p1, p2);
        if((*p1)>(*p2))
        {
                printf("%d is the max no\n", *p1);
        }
        else if((*p1)<(*p2))
        {
                printf("%d is the max no\n", *p2);
        }
        else
        {
                printf("\nEqual\n");
        }
}


