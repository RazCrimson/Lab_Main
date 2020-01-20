#include <iostream>

using namespace std;

class Car
{
    int yearModel, speed;
    string make;

public:
    Car(int model, string &makeType);
    int getYearModel();
    int getSpeed();
    string getMake();
    void accelerate();
    void brake();
};

Car::Car(int model, string &makeType)
{
    yearModel = model;
    make = makeType;
    speed = 0;
}

int Car::getYearModel()
{
    return yearModel;
}

int Car::getSpeed()
{
    return speed;
}

string Car::getMake()
{
    return make;
}

void Car::accelerate()
{
    speed += 5;
}

void Car::brake()
{
    speed -= 5;
}

int main()
{
    int year;
    string make;
    cout << "\nEnter the Year : ";
    cin >> year;
    cout << "\nEnter the make : ";
    cin.sync();
    getline(cin, make);
    Car obj(year, make);
    for (int i = 0; i < 5; i++)
    {
        obj.accelerate();
        cout << "Speed when accelerated " << i + 1 << " times is " << obj.getSpeed() << "\n";
    }
    for (int i = 0; i < 5; i++)
    {
        obj.brake();
        cout << "Speed when braked " << i + 1 << " times is " << obj.getSpeed() << "\n";
    }
    return 0;
}