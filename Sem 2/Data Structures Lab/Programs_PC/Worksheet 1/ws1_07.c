#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int max_index(int *arr,int n)
{
    int max = 0,index = 0;
    for(int i = 0;i<n;i++)
    {
        if(arr[i]>max)
            max = arr[i];
            index = i;
    }
    return index;
}

int main()
{
    int candidate_count=0,precint_count = 0;
    printf("\nEnter the Number of candidates : ");
    scanf("%d",&candidate_count);
    printf("\nEnter the Number of Precinct : ");
    scanf("%d",&precint_count);
    if(candidate_count<=0 || precint_count <=0)
    {
        printf("Error!!");
        exit(0);
    }
    int arr[precint_count][candidate_count];
    int tot[candidate_count];
    memset(tot,0,sizeof(tot));
    for (int i = 0; i < precint_count; i++)
        for (int j = 0; j < candidate_count; j++)
        {
            printf("\nEnter the votes for Candidate %c in Precint %d :",65+j,i+1);
            scanf("%d",&arr[i][j]);
            tot[j] += arr[i][j];
        }
    printf("\nThe Winner is Candidate %c",65+max_index(tot,candidate_count));
    return 0;    
}