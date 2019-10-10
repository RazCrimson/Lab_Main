#include <stdio.h>
#include <stdlib.h>

// Not yet tested

int main()
{
    FILE *sptr,*dptr;
    char ch='1',source[5000]={0},dest[5000]={0};
    printf("\nEnter the path of the source File : ");
    scanf("%[^\n]s",source);
    printf("\nEnter the path of the destination File : ");
    scanf("%[^\n]s",dest);
    sptr=fopen(source,"r");
    if(sptr==NULL)
    {
        printf("\nThe Source File was unable to be opened!");
        exit(-1);
    }
    dptr=fopen(dest,"w+");
    if(dptr==NULL)
    {
        printf("\nThe Destination File was unable to be opened!");
        exit(-1);
    }
    while (ch!=EOF)
    {
        int ID;
        char name[50]={0};
        float Quiz,Lab,Exam;
        fscanf(sptr,"%d\t%s[^\t]\t%f\t%f\t%f",ID,name,Quiz,Lab,Exam);
        fprintf(dptr,"%d\t%s\t%.1f",ID,name,(Quiz+Lab+Exam));
        ch=getc(sptr);
        if(ch!=EOF)
        {
            fprintf(dptr,"\n");
        }

    }
    return 0;
}