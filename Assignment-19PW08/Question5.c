#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long fact(int n)
{
    if (n == 0)
        return 1;
    else
        return n * fact(n - 1);
}

double power(double x, int n)
{
    if (n == 0)
        return 1;
    else
        return x * power(x, n - 1);
}

int fibonacci(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return  fibonacci(n - 2) + fibonacci(n - 1);
}

void reverse(char *arr, int i)
{
    int len = strlen(arr);
    if (i < (len / 2))
    {
        int len = strlen(arr);
        char temp = arr[len - i - 1];
        arr[len - i - 1] = arr[i];
        arr[i] = temp;
        reverse(arr, i + 1);
    }
}

int gcd(int x, int y)
{
    if (y == 0)
        return x;
    else
        return gcd(y, y % x);
}


void q1()
{
    int n;
    printf("\nEnter the number to find Factorial : ");
    scanf("%d",&n);
    printf("\nThe Factorial is %ld",fact(n));
}

void q2()
{
    int n1,n2;
    printf("\nEnter the numbers to find GCD for : ");
    scanf("%d%d",&n1,&n2);
    printf("\nThe GCD is %d",gcd(n1,n2));
}

void q3()
{
    int n;
    printf("\nEnter the number to terms to generate Fibonaci Series for : ");
    scanf("%d",&n);
    printf("\nThe Fibonacci Series is : \n");
    for(int i=0;i<n;i++)
        printf("%d\n",fibonacci(i));
}

void q4()
{
    char *arr = (char *)calloc(1000, sizeof(char));
    printf("\nEnter a String : ");
    getchar();
    scanf("%[^\n]s", arr);
    arr=(char*)realloc(arr,sizeof(char)*(strlen(arr)+1));
    reverse(arr,0);
    printf("\nThe Reverse is %s",arr);
}

void q5()
{
    int p;
    double n;
    printf("\nEnter the number and its power to calculate the value : ");
    scanf("%lf%d",&n,&p);
    printf("\nThe Value is %lf",power(n,p));
}


int main()
{
    int n;
    printf("\nEnter 1 for First sub-heading.\nEnter 2 for Second sub-heading.\
    \nEnter 3 for Third sub-heading.\nEnter 4 for Fourth sub-heading.\
    \nEnter 5 for Fifth sub-heading.\nEnter your choice : ");
    scanf("%d", &n);
    switch(n)
    {
        case 1: q1(); break;
        case 2: q2(); break;
        case 3: q3(); break;
        case 4: q4(); break;
        case 5: q5(); break;
        
    }
    return 0;

}