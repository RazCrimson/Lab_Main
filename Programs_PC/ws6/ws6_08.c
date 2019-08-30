#include <stdio.h>
#include <stdlib.h>

int bubbleSort(int * arr,int n)
{
	for(int i=0;i<n-1;i++)
		for(int j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				arr[j]=arr[j]^arr[j+1];
				arr[j+1]=arr[j]^arr[j+1];
				arr[j]=arr[j]^arr[j+1];
			}
		}
}

int main()
{
	int n=0;
	scanf("%d",&n);
	int* arr=(int*)malloc(sizeof(int)*n);
	for(int i =0;i<n;i++)
		scanf("%d",arr+i);
	bubbleSort(arr,n);
	for(int i=0;i<=n;i+=count)
	{
		for(int count=0)
