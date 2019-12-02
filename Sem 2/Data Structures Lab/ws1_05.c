#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *a,char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

char* itoa( int value, char* result, int base )
{
    if (base < 2 || base > 16)
    {
        *result = 0;
         return result;
    }
    char* out = result;
    int quotient = value;
    do {
        *out = "0123456789abcdef"[ abs( quotient % base ) ];
        ++out;
        quotient /= base;
    } while ( quotient );
    if ( value < 0 && base == 10) *out++ = '-';
    int n = strlen(result);
    for(int i = 0; i < n;i++)
        swap(&result[i],&result[n-i-1]);
    *out = 0;
    return result;
}


void permute(char *arr,int len)
{
     for(int i = 0; i < 3; i++)
     {
        if(arr[i]=='0')
            continue;
        for(int j = 0; j < 3;j++)
        {
            if(i==j)
                continue;
            printf("%c%c%c\n",arr[i],arr[j],arr[3-i-j]);
        }
     }
}

int main()
{
    int n,len;
    char arr[10];
    printf("\nEnter a Number : ");
    scanf("%d",&n);
    if(n<=9)
    {
        printf("\nNo valid permutation possible");
        exit(0);
    }
    itoa(n,arr,10);
    len = strlen(arr);
    permute(arr,len);
    return 0;
}
