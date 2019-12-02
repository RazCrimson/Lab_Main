#include <stdio.h>
#include <stdlib.h>


void print(int *arr, int n)
{
    printf("\n");
    for(int i = 0; i < n; i++)
        printf("%d\t",arr[i]);
}


int main()
{
    int n;
    printf("\nEnter the No. of Elements : ");
    scanf("%d",&n);
    if(n<=0)
    {
        printf("\n Error!! Incorrect value ");
        exit(0);
    }
    int a1[n],a2[n],a3[n];
    printf("\nEnter the Value of A1 : ");
    for(int i = 0; i < n; i++)
        scanf("%d", a1 + i);
    printf("\nEnter the Value of A2 : ");
    for(int i = 0; i < n; i++)
        scanf("%d", a2 + i);
    printf("\nSum of the arrays is : ");
    for(int i = 0; i < n; i++)
    {
        a3[i] = a1[i] + a2[i];
        printf("\n%d",a3[i]);
    }
    int a4[n],a5[n];
    for(int i = 0; i < n; i++)
        a4[i] = a1[i];
    for(int i = 0; i < n; i++)
        a5[i] = a1[i] + a2[i];
    for(int i = 0; i < n; i++)
    {
        int temp = a3[i];
        a3[i] = a3[n-i-1];
        a3[n-i-1] = temp;
    }
    print(a1,n);
    print(a2,n);
    print(a3,n);
    print(a4,n);
    print(a5,n);
    return 0;
}
