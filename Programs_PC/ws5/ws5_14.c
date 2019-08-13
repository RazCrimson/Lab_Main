#include <stdio.h>

int main()
{
    int x,b=0,a=0;
    printf("\nEnter the no : ");
    scanf("%d", &x);
    for (int i = 31; i >= 0; i--)
        printf("%d", (x >> i) & 1);
    for (int i = 31; i >= 0; i--)
    {
        if(((x >> i) & 1)==1)
        {
            break;
        }
        else if(((x >> i) & 1)==0)
        {
            b++;
        }   
    }
    for (int i = 0; i <= 31; i++)
    {
        if(((x >> i) & 1)==1)
        {
            break;
        }
        else if(((x >> i) & 1)==0)
        {
            a++;
        }   
    }
}