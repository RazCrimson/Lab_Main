#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=0,count[10]={0},num;
    printf("\nEnter the No. of elements : ");
    scanf("%d",&n);
    if(n<=0)
	{
		printf("\nERROR!!");
		exit(-1);
	}
    printf("\nEnter the numbers : ");
    while(n--)
    {    
        scanf("%d",&num);
        if(num<=0)
	    {
		    printf("\nERROR!!");
		    exit(-1);
	    }
	    switch(n%10)
        {
            case 0: count[0]++; break;
            case 1: count[1]++; break;
            case 2: count[2]++; break;
            case 3: count[3]++; break;
            case 4: count[4]++; break;
            case 5: count[5]++; break;
            case 6: count[6]++; break;
            case 7: count[7]++; break;
            case 8: count[8]++; break;
            case 9: count[9]++; break;
            default:
        }
        n/=10;
    }
    printf("\n0 : %d times\t1 : %d times\t2 : %d times\t3 : %d times\t4 : %d times\t5 : %d times\t6 : %d times\t7 : %d times\t8 : %d times\t9 : %d times\t",count[0],count[1],count[2],count[3],count[4],count[5],count[6],count[7],count[8],count[9]);
    return 0;
}