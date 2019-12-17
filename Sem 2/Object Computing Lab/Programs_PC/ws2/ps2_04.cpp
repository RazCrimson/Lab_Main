#include <iostream>
#include <cstdlib>

using namespace std;

class Merge
{
    public:
    int merge(int a , int b);
    long merge(long a , long b);
    char merge(char a , char b);
    float merge(float a , float b);
    double merge(double a , double b);
    int* merge(int a[] , int b[]);
    long* merge(long a[] , long b[]);
    char* merge(char a[] , char b[]);
    float* merge(float a[] , float b[]);
    double* merge(double a[] , double b[]);
    
};

int Merge::merge(int a,int b)
{
    return a+b;
}

long Merge::merge(long a,long b)
{
    return a+b;
}

char Merge::merge(char a,char b)
{
    return a+b;
}

float Merge::merge(float a,float b)
{
    return a+b;
}

double Merge::merge(double a,double b)
{
    return a+b;
}

int* Merge::merge(int a[],int b[])
{
    return ;
}


