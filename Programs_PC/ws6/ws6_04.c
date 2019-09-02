#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i=0;
    printf("\nEnter the No. of Positive Intergers : ");
    scanf("%d",&n);
    int *arr=(int*) malloc(sizeof(int)*(n));
    printf("\nEnter the Elements of the array");
    for(i=0;i<n-1;i++)
        scanf("%d",*(arr+i));
    for(i=0;i<n-1;i++)
    {
        if(*(arr+i)>*(arr+i+1))
            break;
    }
    if(i==n-1)
        printf("\nThe elements are sorted.");
    else
        printf("\nThe elements are not sorted.");
        

}