#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int count[11]={0},sum=0;
    srand(time(0));
    for(int i=0;i<3600;i++)
    {
        sum=(rand()%6)+(rand()%6)+2;
        switch(sum)
        {
            case 2: count[0]++; break;
            case 3: count[1]++; break;
            case 4: count[2]++; break;
            case 5: count[3]++; break;
            case 6: count[4]++; break;
            case 7: count[5]++; break;
            case 8: count[6]++; break;
            case 9: count[7]++; break;
            case 10: count[8]++; break;
            case 11: count[9]++; break;
            case 12: count[10]++; break;
       }
    }
    printf("\n2 : %d times\t3 : %d times\t4 : %d times\t5 : %d times\t6 : %d times\t7 : %d times\t8 : %d times\t9 : %d times\t10 : %d times\t11 : %d times\t12 : %d times\t",count[0],count[1],count[2],count[3],count[4],count[5],count[6],count[7],count[8],count[9],count[10]);
    return 0;
}