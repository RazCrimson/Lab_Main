#include <stdio.h>
#include <stdlib.h>

int find(char *str,int maxlength,char find)
{
    for(int i=0;i<maxlength;i++)
        if(find==str[i])
            return i;
    return -1;
}

int main()
{
	int *arr=(int*)malloc(sizeof(char)*1024);
	scanf("%[^\n]*c",arr);
	for(int i = 0;i<find('\n');i++)
	{
        
    }