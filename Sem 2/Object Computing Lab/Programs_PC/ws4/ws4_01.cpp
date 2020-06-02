#include <iostream>

using namespace std;

class Time
{
    int hours, minutes, seconds;

public:
    Time(int h, int m, int secs);
    void printTime() const;
    Time operator+(const Time &b);
    bool operator<(const Time &b);
};

Time::Time(int h, int m, int s)
{
    if (h < 0)
        h = 0;
    if (m < 0)
        m = 0;
    if (s < 0)
        s = 0;
    hours = h % 24;
    minutes = m % 60;
    seconds = s % 60;
}

void Time::printTime() const
{
    cout << hours << " : " << minutes << " : " << seconds;
}

Time Time::operator+(const Time &b)
{
    int h, m, s;
    h = (hours + b.hours) % 24;
    m = (minutes + b.minutes) % 60;
    s = (seconds + b.seconds) % 60;
    return {h, m, s};
}

bool Time::operator<(const Time &b)
{
    if (hours < b.hours)
        return true;
    else if (hours == b.hours)
    {
        if (minutes < b.minutes)
            return true;
        else if (minutes == b.minutes)
        {
            if (seconds < b.seconds)
                return true;
        }
    }
    return false;
}

int main()
{
    Time a(10, 20, 30), b(20, 30, 40);
    cout << "\na is : ";
    a.printTime();
    cout << "\nb is : ";
    b.printTime();
    cout << "\nIs a < b ?" << (a < b);
    cout << "\na + b is : ";
    (a + b).printTime();
    cout << "\na is : ";
    a.printTime();
    int n;
    cin >> n ;
}