#include <iostream>

using namespace std;


class Point
{
    int x_co, y_co;

  public:
    Point(int,int);
    void set(int x, int y);
    Point add(Point b);
    Point subtract(Point b);
    void reset();
    bool isOrigin();
    void display();
};

Point::Point(int x, int y)
{
    x_co = x;
    y_co = y;
}


void Point::display()
{
    cout << "X Coordinate : " << x_co << endl
         << "Y Coordinate : " << y_co << endl;
}

class RationalNumber
{
    int x_co, y_co;

  public:
    RationalNumber(int,int);
    void display();
};

RationalNumber::RationalNumber(int x, int y)
{
    x_co = x;
    y_co = y;
}

void RationalNumber::display()
{
    cout << "Numerator : " << x_co << endl
         << "Denomenator : " << y_co << endl;
}

int main()
{
    Point *P1 = new Point(10,10);
    RationalNumber *R1 = (RationalNumber *)P1;
    P1->display();
    R1->display();
}