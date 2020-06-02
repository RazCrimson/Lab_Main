#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
	int n=0,Max=INT_MIN,Min=INT_MAX;
	printf("\nEnter the Size of Array : ");
	scanf("%d",&n);
	int *arr=(int*)malloc(sizeof(int)*n);
	for(int i =0;i<n;i++)
    {
		scanf("%d",arr+i);
        if(arr[i]<Min)
            Min=i;
        else if(arr[i]>Max)
            Max=i;
    }
    printf("\nThe Minimum is %d\nTHe maximum is %d",arr[Min],arr[Max]);
    return 0;
}
