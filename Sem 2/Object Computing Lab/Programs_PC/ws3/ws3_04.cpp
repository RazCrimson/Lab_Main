#include <iostream>

using namespace std;

class Time
{
    int hours, minutes, seconds;

public:
    Time();
    Time(int, int, int);
    Time operator+(Time &);
};

Time::Time()
{
    cout << "\nEnter the Hours : ";
    cin >> hours;
    cout << "\nEnter the Minutes : ";
    cin >> minutes;
    cout << "\nEnter the Seconds : ";
    cin >> seconds;
}

Time::Time(int qHours, int qMin, int qSeconds)
{
    hours = qHours;
    minutes = qMin;
    seconds = qSeconds;
}

Time Time::operator+(Time &b)
{
    int sum = 0;
    sum = seconds + b.seconds;
    minutes += sum / 60;
    seconds = sum % 60;
    sum = minutes + b.minutes;
    minutes = sum % 60;
    hours += sum / 60;
    sum = hours + b.hours;
    hours = sum % 24;
}