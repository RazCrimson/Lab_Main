#include <iostream>

using namespace std;


class Point
{
    int x_co, y_co;

  public:
    void set(int x, int y);
    Point add(Point b);
    Point subtract(Point b);
    void reset();
    bool isOrigin();
    void display();
};

void Point::set(int x, int y)
{
    x_co = x;
    y_co = y;
}

Point Point::subtract(Point b)
{
    Point c;
    c.x_co = x_co - b.x_co;
    c.y_co = y_co - b.y_co;
    return c;
}

Point Point::add(Point b)
{
    Point c;
    c.x_co = x_co + b.x_co;
    c.y_co = y_co + b.y_co;
    return c;
}

void Point::reset()
{
    x_co = 0;
    y_co = 0;
}

bool Point::isOrigin()
{
    if (x_co == 0 && y_co == 0)
        return true;
    else
        return false;
}

void Point::display()
{
    cout << "X Coordinate : " << x_co << endl
         << "Y Coordinate : " << y_co << endl;
}

class Rectangle
{
    float length, breadth;

  public:
    void reset();
    void setBreadth(float breadth1);
    void setLength(float length1);
    float getBreadth();
    float getLength();
    float perimeter();
    float area();
};

void Rectangle::setLength(float length1)
{
    length = length1;
}

void Rectangle::setBreadth(float breadth1)
{
    breadth = breadth1;
}

float Rectangle::getBreadth()
{
    return breadth;
}

float Rectangle::getLength()
{
    return length;
}

void Rectangle::reset()
{
    breadth = 0;
    length = 0;
}

float Rectangle::area()
{
    return length*breadth;
}

float Rectangle::perimeter()
{
    return 2*(length*breadth);
}


int main()
{
    Rectangle R1;
    R1.setBreadth(10);
    R1.setLength(10);
}