#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int ways(int n)
{
    if(n == 0)
        return 1;
    else if(n>0)
        return ways(n-1)+ways(n-2);
    else 
        return 0;
}

int main()
{
    int n =0;
    printf("\nEnter the number for n :");
    scanf("%d",&n);
    printf("THe ways are : %d",ways(n));
    return 0;
}

