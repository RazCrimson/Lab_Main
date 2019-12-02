#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main()
{
    char chk,arr[10] = {'B','C','A','D','A','B','C','D','A','C'};
    int marks = 0;
    for(int i=0;i<10;i++)
    {
        printf("\nEnter the answer for the %dth question :", i+1);
        scanf("%c",&chk);
        getchar();
        chk = toupper(chk);
        if(chk == arr[i])
            marks += 4;
        else
            marks -= 1;
    }
    printf("Total Marks : %d",marks);
    return 0;
}
