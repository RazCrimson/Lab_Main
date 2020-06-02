#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int age[100];
    char name[100][100];
    int count=0;
    printf("\nEnter the No. of Records : ");
    scanf("%d",&count);
    if(count<1 || count>100)
    {
        printf("Please Enter a valid amount of records!");
        exit(0);
    }
    for(int i=0;i<count;i++)
    {
        printf("Enter the Name of record #%d : ",i);
        scanf("%s",&name[i][0]);
        strupr(&name[i][0]);
        printf("Enter the Age of record #%d : ",i);
        scanf("%d",&age[i]);
    }
	for(int i=0;i<count-1;i++)
		for(int j=0;j<count-i-1;j++)
		{
			if(strcmp(&name[j][0],&name[j+1][0])>0)
			{
				int temp1=0;
                char temp[100]={0};
                strcpy(&temp,&name[j+1][0]);
                strcpy(&name[j+1][0],&name[j][0]);
                strcpy(&name[j][0],&temp);
				temp1=age[j+1];
                age[j+1]=age[j];
                age[j]=temp1;
			}
		}
    for(int i=0;i<count;i++)
        printf("\nNAME : %s | AGE : %d",&name[i][0],age[i]);
    return 0;
}