#include <iostream>

using namespace std;

class Coordinate
{

    double xVal, yVal;

public:
    Coordinate(double = 0, double = 0);
    void display();
    friend void conPol(Coordinate&);
    // Question: why should a friend function return another object?
};

Coordinate::Coordinate(double x, double y)
{
    xVal = x;
    yVal = y;
}

void Coordinate::display()
{
    cout << "\nX coordinate : " << xVal << "\nY Coordinate : " << yVal;
}

void conPol(Coordinate& b)
{   



}
