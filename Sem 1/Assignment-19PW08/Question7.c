#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int main()
{
    int Total[2]={0},min=0,max=0,Price[4]={5000,10000,2000,8000},Quantity[4]={0};
    char Items[4][15]={"MP3 Player","WII     ","DVD Player","Digital Camera"};
    printf("============================================\
    \nThe number of MP3 Player sold: ");
    scanf("%d",&Quantity[0]);
    printf("\nThe number of WII sold: ");
    scanf("%d",&Quantity[1]);
    printf("\nThe number of DVD Player sold: ");
    scanf("%d",&Quantity[2]);
    printf("\nThe number of Digital Camera sold: ");
    scanf("%d",&Quantity[3]);
    printf("============================================\
    \nThe statistic of sales is as follows:\
    \n============================================ \
    \nProduct Unit  		Price 	        QTY    Total  Price \
    \n-------------     	------          ---    ------------");
    for (int i = 0; i < 4; i++)
    {
        printf("\n%s\t\t%d\t\t%d\t%d",&Items[i][0],Price[i],Quantity[i],Price[i]*Quantity[i]);
        Total[0]+=Quantity[i];
        Total[1]+=Price[i]*Quantity[i];
        if(Quantity[i]>Quantity[max])
            max=i;
        if(Quantity[i]<Quantity[min])
            min=i;
    }
    printf("\n\t\t\t\tTotal   %d\t%d",Total[0],Total[1]);
    printf("\n============================================\
    \nProduct sold most:  %s %d",&Items[max],Quantity[max]);
    printf("\nProduct sold least:  %s %d",&Items[min],Quantity[min]);
    return 0;    
}