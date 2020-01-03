#include <iostream>
#include <cstdlib>

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

int main()
{
    int num=NULL,*ptr=NULL;
    Point p1, p2;
    p1.set(1, 2);
    p2.set(4, 6);
    Point p3 = p1.add(p2);
    p3.display();
    
    
    
}