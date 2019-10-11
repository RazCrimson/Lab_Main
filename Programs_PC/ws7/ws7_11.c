#include <stdio.h>
#include <string.h>

int main()
{
    char s[] = "123456789";
    int i=0,j=0,len=strlen(s);
    for (int i = 0; i < (len+1)/2; i++)
    {
        for(j=0;j<len-i;j++)
            printf(" ");
        for(j=i+1;j<2*i+1;j++)
            print("%c ",&s[j-1]);
        
    }
     
}