#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int bubbleSort(int *arr,int n)
{
	for(int i=0;i<n-1;i++)
		for(int j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=temp;
			}
		}
}

int main()
{
    int n=0,coin=0,sum=0,ur=0;
    scanf("%d",&n);
    int *arr=(int*)malloc(sizeof(int)*(n));
    for(int i=0;i<n;i++)
    {
        scanf("%d",arr+i);
        sum+=arr[i];        
    }
    bubbleSort(arr,n);
    printf("sum=%d",ur);
    for(int i=1;i<n/2;i++)
    {
        if(ur<=(sum+1)/2)
        {
            ur+=arr[n-i-1];
            printf("sdf");
            coin++;
        }
        if(ur<=(sum+1)/2)
        {
            ur+=arr[i];
            coin++;
        }
    }
    printf("sum=%d",ur);
    printf("\n%d",coin);
    return 0;
}