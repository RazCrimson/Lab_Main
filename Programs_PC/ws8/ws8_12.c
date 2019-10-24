#include<stdio.h>
void main()
{
        int A[10], n, *p=A, i;
        printf("\nEnter no of elements(max-10):");
        scanf("%d", &n);
        printf("\nEnter elements:");
        for(i=0; i<n; i++)
        {
                printf("\nelement %d=", i+1);
                scanf("%d", A+i);
        }
        printf("\nPrinted using pointer:\n");
        for(i=0; i<n; i++)
        {
                printf("Element %d=%d\n", i+1, *(p+i));
        }
}
