#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void swap(int *x, int *y) 
{ 
    *x = *x ^ *y; 
    *y = *x ^ *y;
    *x = *x ^ *y;
}

int main()
{
	int n=0,temp=0;
	printf("\nEnter the Size of Array : ");
	scanf("%d",&n);
    if(n<=0)
	{
		printf("\nERROR!! Array index cant be negative.");
		exit(-1);
	}
	int *arr=(int*)malloc(sizeof(int)*n);
	printf("Enter the Elements of the array : ");
    for(int i =0;i<n;i++)
	    scanf("%d",arr+i);
    for(int i=0;i<=(n-1)/2;i++)
        swap(arr+i,arr+n-i-1);
    for(int i=0;i<n;i++)
        printf("%d\t",arr[i]);
    return 0;
}