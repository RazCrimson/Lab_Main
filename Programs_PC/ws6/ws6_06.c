#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
}



void bubbleSort(int *arr, int n) 
{ 
   int i, j,flg=0; 
   for (i = 0; i < n-1; i++)       
    {
        for (j = 0; j < n-i-1; j++)  
        {
            if (arr[j] > arr[j+1]) 
            {
                swap(&arr[j], &arr[j+1]); 
                flg=1;
            }
        }    
        if(flg==0)
            break;
    }
}



int hasArrayTwoCandidates(int *arr,int n,int sum)
{
    
    bubbleSort(arr,n);
    int l=0,r=n-1;
    int count = 0;
    while(l<r)
    {
        if(arr[l]+arr[r]==sum)
        {
            count++;
            l++;
        }
        else if(arr[l]+arr[r]<sum)
            l++;
        else 
            r--;
    }
    return count;
}


int main()
{
    int res=0,n,i=0,sum=0;
    printf("\nEnter the No. of Elements : ");
    scanf("%d",&n);
    printf("\nEnter the Sum : ");
    scanf("%d",&sum);
    if(n<=0)
    {
        printf("\nERROR!! Array cant have negative no. of elements");
        exit(-1);
    }
    int *arr=(int*) malloc(sizeof(int)*n);
    printf("\nEnter the Elements of the array : ");
    for(i=0;i<=n-1;i++)
    {
        scanf("%d",(arr+i));
    }
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    res=hasArrayTwoCandidates(arr,n,sum);
    printf("\nThe no. of elements in the array with the sum were : %d",res);
    return 0;
}