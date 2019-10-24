#include<stdio.h>

int value(int x)
{
        if(x<=0)
        return 0;
        else
        return value(x-1)+2;
}

int main()
{
        int y,p;
        printf("the value to be entered\n");
        scanf("%d",&y);
        p=value(y);
        printf("%d\n",p);
        return 0;
}

