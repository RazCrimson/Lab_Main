#include <stdio.h?>
#include <stdlib.h>

int main()
{
    int n,i=0,k;
    printf("\nEnter the No. of Elements : ");
    scanf("%d",&n);
    printf("\nEnter the Number : ");
    scanf("%d",&k);
    if(n<=0)
    {
        printf("\nERROR!! Array cant have negative no. of elements");
        exit(-1);
    }
    int *arr=(int*) malloc(sizeof(int)*(n));
    printf("\nEnter the Elements of the array");
    for(i=0;i<n-1;i++)
        scanf("%d",*(arr+i));
    hasArrayTwoCandidates(&arr,n,k);