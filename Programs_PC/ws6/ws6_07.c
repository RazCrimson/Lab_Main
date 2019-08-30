#include <stdio.h>
#include <limits.h>


int main()
{
    int min=INT_MAX,n=0;
    printf("\nEnter the No. of Elements : ");
    scanf("%d",&n);
    if(n<=0)
    {
        printf("\nERROR!! Array cant have negative no. of elements");
        exit(-1);
    }
    int *arr=(int*) malloc(sizeof(int)*n);
    printf("\nEnter the Elements of the array : ");
    for(int i=0;i<=n-1;i++)
    {
        scanf("%d",(arr+i));
        if(arr[i]>-1&&arr[i]<min)
            min=arr[i];
    }
    printf("\nThe required positive interger is %d",min-1);
    return 0;

}