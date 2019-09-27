#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char arr[1000];
    int i=0,len=0,count[3]={0};
    printf("\nWorksheet 8: Program 3");
    printf("\nEnter a string within 999 characters  : ");
    scanf("%s",arr);
    len=strlen(arr);
    for(i=0;i<len;i++)
    {
        if(islower(arr[i]))
            count[0]++;
        else if(isupper(arr[i]))
            count[1]++;
        else 
            count[2]++;
    }
    printf("\nThe No of Lower characters : %d\nThe No of Upper characters : %d\nThe No of Special characters(including non printables) : %d\n",count[0],count[1],count[2]);
    return 0;
}