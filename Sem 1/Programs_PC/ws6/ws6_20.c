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
        if(num<0)
	    {
		    printf("\nERROR!!");
		    exit(-1);
	    }
	    if(n<10)
            count[0]++;
        else if(n<20)
            count[1]++;
        else if(n<30)
            count[2]++;
        else if(n<40)
            count[3]++;
        else if(n<50)
            count[4]++;
        else if(n<60)
            count[5]++;
        else if(n<70)
            count[6]++;
        else if(n<80)
            count[7]++;
        else if(n<90)
            count[8]++;
        else if(n<100)
            count[9]++;
        else
        {
            printf("\nThe valuse is greater than 100.");
        }
    }
    printf("\n0 - 9 : %d \t10 - 19 : %d \t20 - 29 : %d \t30 - 39 : %d \t40 - 49 : %d \t50 - 59 : %d \t60 - 69 : %d \t70 - 79 : %d \t80 - 89 : %d \t90 - 99 : %d \t",count[0],count[1],count[2],count[3],count[4],count[5],count[6],count[7],count[8],count[9]);
    return 0;
}