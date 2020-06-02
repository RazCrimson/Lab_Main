#include <stdio.h>
#include <stdlib.h>

// Not yet tested
void read(FILE *ptr)
{
    do
    {
        char Student_Name[50]={0};
        int Student_ID;
        float Quiz_Marks,Lab_Marks,Exam_Marks;
        printf("\nEnter the Student Student_ID: ");
        scanf("%d",Student_ID);
        printf("\nEnter the Student_Name of the student : ");
        scanf("%[^\n]s",Student_Name);
        printf("\nEnter the Marks of Quiz_Marks : ");
        scanf("%d",Quiz_Marks);
        printf("\nEnter the Marks of Lab : ");
        scanf("%d",Lab_Marks);
        printf("\nEnter the Marks of Exam : ");
        scanf("%d",Exam_Marks);
        fprintf(ptr,"%d\t%s\t%f\t%f\t%f\n",Student_ID,Student_Name,Quiz_Marks,Lab_Marks,Exam_Marks);
        printf("Do u want to continue? (Press 1) : ");
        scanf("%d",&Student_ID);
        if(Student_ID!=1)
            break;
    }while(1);
}

int main(int argc,char *argv[])
{
    FILE *sptr,*dptr;
    char ch;
    printf("Do you want to append(a) or write(w) the file?(press any other key to skip it) : ");
    scanf("%d",&ch);
    if(ch == 'a')
        sptr=fopen(&argv[1][0],"a+");
    else if(ch == 'w')
        sptr=fopen(&argv[1][0],"w+");
    if((ch=='a'||ch=='w')&&sptr==NULL)
    {
        printf("\nThe Source File was unable to be opened!");
        exit(-1);
    }
    else if(ch=='a'||ch=='w')
    {
        read(sptr);
        fclose(sptr);
    }
    sptr=fopen(&argv[1][0],"r");
    dptr=fopen(&argv[2][0],"w+");
    if(sptr==NULL)
    {
        printf("\nThe Source File was unable to be opened!");
        exit(-1);
    }
    if(dptr==NULL)
    {
        printf("\nThe Destination File was unable to be opened!");
        exit(-1);
    }
    while (ch!=EOF)
    {
        int Student_ID;
        char Student_Name[50]={0};
        float Quiz_Marks,Lab_Marks,Exam_Marks;
        fscanf(sptr,"%d\t%s[^\t]\t%f\t%f\t%f\n",Student_ID,Student_Name,Quiz_Marks,Lab_Marks,Exam_Marks);
        fprintf(dptr,"%d\t%s\t%.1f\n",Student_ID,Student_Name,(Quiz_Marks+Lab_Marks+Exam_Marks));
        ch=getc(sptr);
        if(ch!=EOF)
        {
            fprintf(dptr,"\n");
        }

    }
    return 0;
}