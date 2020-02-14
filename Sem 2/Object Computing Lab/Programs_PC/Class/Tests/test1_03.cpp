#include <iostream>
#include <cstdlib>

using namespace std;

struct Point
{
    int x_co, y_co;

public:
    Point();
    Point(int x, int y);
    void set(int x, int y);
    Point operator+(Point &b);
    Point operator-(Point &b);
    Point& operator=(Point &b);
    void reset();
    bool isOrigin();
    void display();
};


Point::Point(int x, int y)
{

    cout << "conversion x " << x << "y "<<y<<endl;
    x_co = x;
    y_co = y;
}

Point::Point()
{
    x_co = 0;
    y_co =0;
}

void Point::set(int x, int y)
{
    x_co = x;
    y_co = y;
}

Point Point::operator-(Point &b)
{
    return {x_co - b.x_co, y_co - b.y_co};
}

Point Point::operator+(Point &b)
{
    return {x_co + b.x_co, y_co + b.y_co};
}

Point& Point::operator=(Point &b)
{
    x_co = b.x_co;
    y_co = b.y_co;
    return *this;
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

int main()
{
    Point p1, p2 = {4,6};
    p1.set(1, 2);
    Point p3 = p1 + p2;
    p3.display();
}