#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void jacob()
{
    int n=9,Guess,Sum=0;
    while(n--)
    {
        printf("Enter your guess : ");
        scanf("%d",&Guess);
        Sum+=Guess;
        printf("\nYou are Wrong!!");
    }
    printf("\nThe correct Number is : %d",55-Sum);
}

void thabo()
{
    int n[10]={0},Guess,Sum=0;
    for(int i=0;i<10;i++)
    {
        printf("Enter your guess : ");
        scanf("%d",&Guess);
        n[Guess]=1;
        printf("\nYou are Wrong!!");
    }
    for(int i=0;i<10;i++)
        if(n[i]==0)
            Sum=i;
    printf("\nThe correct Number is : %d",Sum);
}

int main(){

    int choice=0;
    printf("\nGuess Game!!\nTry to Guess the number within the least tries.");
    printf("\n0-Jacob\n1-Thabo\nEnter your choice : ");
    scanf("%d",&choice);
    if(choice==0)
        jacob();
    else if(choice==1)
        thabo();
    else
        printf("Error!");
    return 0;
    }

