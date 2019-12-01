#include <stdio.h> 
#include <stdlib.h>


int bin(int n, int k) 
{ 
    int res = 1; 
    if (k > n - k) 
    k = n - k; 
    for (int i = 0; i < k; ++i) 
    { 
        res *= (n - i); 
        res /= (i + 1); 
    } 
      
    return res; 
} 

void Pascal(int n) 
{ 
    for (int line = 0; line < n; line++) 
    { 
        for (int i = 0; i <= line; i++) 
            printf("%d ", 
                    bin(line, i)); 
        printf("\n"); 
    } 
} 
  
  
int main() 
{ 
    int n;
    printf("Enter the no of lines of Pascal's Triangle : ") ;
    if(n<=0)
    {
        printf("ERROR!! Negative Value");
        exit(0);
    }
    Pascal(n); 
    return 0; 
} 