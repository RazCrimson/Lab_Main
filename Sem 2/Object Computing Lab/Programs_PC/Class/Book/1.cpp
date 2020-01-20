#include <iostream>

using namespace std;

string months[12] = {"January", "Feburary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

class Date
{
    int day, month, year;

public:
    int read();
    void display1();
    void display2();
    void display3();
};

int Date::read()
{
    int temp;
    cout << "Enter the day : ";
    cin >> temp;
    if (temp > 0 && temp < 32)
        day = temp;
    else
    {
        cout << "Invaild Values!" << endl;
        delete this;
    }
    cout << "Enter the month : ";
    cin >> temp;
    if (temp > 0 && temp < 13)
        month = temp;
    else
    {
        cout << "Invaild Values!" << endl;
        delete this;
    }
    cout << "Enter the year(in 4 digits) : ";
    cin >> temp;
    if (temp > 1900)
        year = temp;
    else
    {
        cout << "Invaild Values!" << endl;
        delete this;
    }
}

void Date::display1()
{
    cout << day << "/" << month << "/" << year << endl;
}

void Date::display2()
{
    cout << months[month - 1] << " " << day << ", " << year << endl;
}

void Date::display3()
{
    cout << day << " " << months[month - 1] << " " << year << endl;
}

int main()
{
    cout << "Enter the date to display it in diffrent formats.\n";
    Date *ptr = new Date;
    ptr->read();
    ptr->display1();
    ptr->display2();
    ptr->display3();
}