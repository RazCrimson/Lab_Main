#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


char in[8][8]={0}, sol[8][8]={0};

void print_in()
{

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
            printf("%c",in[i][j]);
        printf("\n");
    }

}

void print_sol()
{

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
            printf("%c",sol[i][j]);
        printf("\n");
    }
    
}

void realize()
{
    
}

int valid(int x, int y)
{
    if(x<8&&y<8)
        return 1;
    else
        return 0;
}


int find_path(int x, int y)
{
    printf("called");
    if(x==7 && y==7)
        return 1;
    else if(valid(x+1,y)&&find_path(x+1,y))
    {
        if(in[x][y]=='_')
        {
            sol[x][y]=1;
            return 1;
        }
        else
            return 0;
    }
    else if(valid(x,y+1)&&find_path(x,y+1))
    {
        if(in[x][y]=='_')
        {
            sol[x][y]=1;
            return 1;
        }
        else
            return 0;
    }
    else if(valid(x-1,y)&&find_path(x-1,y))
    {
        if(in[x][y]=='_')
        {
            sol[x][y]=1;
            return 1;
        }
        else
            return 0;
    }
    else if(valid(x,y-1)&&find_path(x,y-1))
    {
        if(in[x][y]=='_')
        {
            sol[x][y]=1;
            return 1;
        }
        else
            return 0;
    }
    else
    {
        return 0;
    }
    
}


int main()
{
    printf("\nEnter the input for the maze :\n");
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
            in[i][j]=getche();
        printf("\n");
    }
    printf("The Input Maze is :\n");
    print_in();
    if(find_path(0,1)==1)
        print_sol();
    else
        printf("\n No Path Found!\n");
    getch();
    return 0;
}