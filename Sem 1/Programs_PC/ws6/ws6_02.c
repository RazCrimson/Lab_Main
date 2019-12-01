#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i=0;
	unsigned n;
    	printf("\nEnter the No. upto wich the primes are to be printed : ");
    	scanf("%d",&n);
	int arr[n];
    	for(i=2;i<=n;i++)
    	{
       	 arr[i-2]=i;
    	}
    	for(i=2;i<n;i++)
    	{
       	 if(arr[i-2]==-1)
           	 continue;
       	 for(int kill=i*i;kill<=n;kill+=i)
            	arr[kill-2]=-1;
    	}
    	for(i=0;i<n-1;i++)
    	{
       		if(arr[i]==-1)
            	continue;
        	printf("%d\n",arr[i]);
	}
	printf("Time elapsed is %f seconds", t);
	return 0;
}
