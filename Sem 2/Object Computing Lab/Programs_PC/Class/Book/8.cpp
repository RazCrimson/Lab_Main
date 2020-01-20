#include <iostream>

using namespace std;

class Circle
{
    double radius;
    static double pi;

public:
    Circle();
    Circle(double rad);
    void setRadius(double);
    double getRadius();
    double getArea();
    double getDiameter();
    double getCircumference();
};

double Circle::pi = 3.14159;

Circle::Circle()
{
    radius = 0;
}

Circle::Circle(double rad)
{
    radius = rad;
}

void Circle::setRadius(double rad)
{
    radius = rad;
}

double Circle::getRadius()
{
    return radius;
}

double Circle::getArea()
{
    return pi * radius * radius;
}

double Circle::getDiameter()
{
    return 2 * radius;
}

double Circle::getCircumference()
{
    return 2 * pi * radius;
}

int main()
{
    Circle one;
    double rad;
    cout << "Enter the circle's Radius : ";
    cin >> rad;
    one.setRadius(rad);
    cout << "\nThe Radius : " << one.getRadius()
         << "\nThe Diameter : " << one.getDiameter()
         << "\nThe Area : " << one.getArea()
         << "\nThe Circumference : " << one.getCircumference();
    return 0;
}