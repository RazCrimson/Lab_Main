#include <stdio.h>
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
	int n=0;
	printf("\nEnter the Size of Array : ");
	scanf("%d",&n);
	int *arr=(int*)malloc(sizeof(int)*n);
	for(int i =0;i<n;i++)
		scanf("%d",arr+i);
	bubbleSort(arr,n);
    for(int i=0;i<n-1;i++)
	{
		if(arr[i]==arr[i+1])
        {
            for(int j=1;j<n-1;j++)
                arr[j]=arr[j+1];
            i--;
            n--;
        }
    }
    printf("Duplicates remoned : ");
    for(int i=0;i<n;i++)
        printf("%d\t",arr[i]);
    return 0;
}