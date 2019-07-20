#include <stdio.h>
#include <stdlib.h>

long fact(int f)
{
        if(f<0)
        {
                printf("\nERROR!!!");
                exit(-1);
        }
        else if(f==0)
                return 1;
        long res=1;
        for(int i=1;i<=f;i++)
                res*=i;
        return res;
}


int main()
{
    int n;
    double res=0;
    printf("\n##### Exponential Calculation ####");
    scanf("%d",n);
    if(n<0)
    {
        printf("\nERROR!!");
        exit(-1);
    }
    for(int i = 0; i <= n; i++)
    {
        res+=1.0/fact(i);
    }
    printf("\nResult is %f",res);
    return 0;
}