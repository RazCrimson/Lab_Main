#include <stdio.h>  /* errors */
#include <stdlib.h>

int main()
{
	short i;
    unsigned n;
    printf("\n\t\t##### Printing a  Palindrome #####");
	printf("\nEnter the value of n : ");
    scanf("%u",&n);
    if(n<=0&&n>17)
    {
        printf("\nERROR!!");
        exit(7);
    }
    char* str=malloc(n);
    for(i=0;i<=(n-1)/2;i++)
	    *(str+i)=*(str-i-2)=(i+1)-'0';
	printf("\n%s",*str);
	return 0;
}