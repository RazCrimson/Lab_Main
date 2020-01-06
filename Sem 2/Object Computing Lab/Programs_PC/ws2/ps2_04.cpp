#include <iostream>

using namespace std;

class Merge
{
public:
    int merge(int a, int b);
    long merge(long a, long b);
    char merge(char a, char b);
    float merge(float a, float b);
    double merge(double a, double b);
    int *merge(int a[], int b[], int alen, int blen);
    long *merge(long a[], long b[], int alen, int blen);
    char *merge(char a[], char b[], int alen, int blen);
    float *merge(float a[], float b[], int alen, int blen);
    double *merge(double a[], double b[], int alen, int blen);
};

int Merge::merge(int a, int b)
{
    return a + b;
}

long Merge::merge(long a, long b)
{
    return a + b;
}

char Merge::merge(char a, char b)
{
    return a + b;
}

float Merge::merge(float a, float b)
{
    return a + b;
}

double Merge::merge(double a, double b)
{
    return a + b;
}

int *Merge::merge(int a[], int b[], int alen, int blen)
{
    int *arr = new int[alen + blen];
    for (int i = 0; i < alen; i++)
        arr[i] = a[i];
    for (int i = 0; i < blen; i++)
        arr[i + alen] = a[i];
    return arr;
}

float *Merge::merge(float a[], float b[], int alen, int blen)
{
    float *arr = new float[alen + blen];
    for (int i = 0; i < alen; i++)
        arr[i] = a[i];
    for (int i = 0; i < blen; i++)
        arr[i + alen] = a[i];
    return arr;
}

double *Merge::merge(double a[], double b[], int alen, int blen)
{
    double *arr = new double[alen + blen];
    for (int i = 0; i < alen; i++)
        arr[i] = a[i];
    for (int i = 0; i < blen; i++)
        arr[i + alen] = a[i];
    return arr;
}

char *Merge::merge(char a[], char b[], int alen, int blen)
{
    char *arr = new char[alen + blen];
    for (int i = 0; i < alen; i++)
        arr[i] = a[i];
    for (int i = 0; i < blen; i++)
        arr[i + alen] = a[i];
    return arr;
}

long *Merge::merge(long a[], long b[], int alen, int blen)
{
    long *arr = new long[alen + blen];
    for (int i = 0; i < alen; i++)
        arr[i] = a[i];
    for (int i = 0; i < blen; i++)
        arr[i + alen] = a[i];
    return arr;
}