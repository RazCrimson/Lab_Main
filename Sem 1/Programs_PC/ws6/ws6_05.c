#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i=0,max;
    printf("\nEnter the No. of Positive Intergers : ");
    scanf("%d",&n);
    int *arr=(int*) malloc(sizeof(int)*(n));
    printf("\nEnter the Elements of the array");
    for(i=0;i<n-1;i++)
        scanf("%d",*(arr+i));
    max=*(arr);
    for(i=1;i<n-1;i++)
        if(*(arr+i)>max)
            max=i;
    printf("\nThe peak of the array elements is the %dth element and it is %d",i,*(arr+i))    ;
    return 0;
}