#include <iostream>

using namespace std;

class Complex
{

    int real, imaginary;

public:
    Complex();
    Complex(double, double);
    ~Complex();
    friend Complex operator+(Complex &, Complex &);
    friend Complex operator-(Complex &, Complex &);
    friend Complex operator*(Complex &, Complex &);
};

Complex::Complex()
{
    real = 0;
    imaginary = 0;
}

Complex::Complex(double rl, double im)
{
    real = rl;
    imaginary = im;
}

Complex operator+(Complex &a, Complex &b)
{
    Complex result;
    result.real = a.real + b.real;
    result.imaginary = a.imaginary + b.imaginary;
    return result;
}

Complex operator-(Complex &a, Complex &b)
{
    Complex result;
    result.real = a.real - b.real;
    result.imaginary = a.imaginary - b.imaginary;
    return result;
}

Complex operator*(Complex &a, Complex &b)
{
    Complex result;
    result.real = (a.real * b.real) + (a.imaginary * b.imaginary);
    result.imaginary = (b.real * a.imaginary) + (b.imaginary * a.real);
    return result;
}