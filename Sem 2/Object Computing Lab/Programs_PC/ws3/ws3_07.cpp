#include <iostream>
#include <ctime>

using namespace std;

class Car
{

    string bodyStyle;
    int engineSize, colourCode;

public:
    Car(string &);
    void display();
    Car operator=(Car &);
};

Car::Car(string &style)
{
    engineSize = 0;
    colourCode = 0;
    bodyStyle = style;
}

void Car::display()
{
    cout << "\nEngine Size : " << engineSize << "\nBody Style : " << bodyStyle << "\nColour Code : " << hex << colourCode;
}

Car Car::operator=(Car& b)
{
    bodyStyle = b.bodyStyle;
    engineSize = b.engineSize;
    colourCode = b.colourCode;
}

