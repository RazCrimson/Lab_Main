#include <iostream>

using namespace std;

class Number
{
    int x;

public:
    void display() const
    {
        increment();
        cout << x;
    }
    int increment()
    {
        x++;
    }
    Number(int a)
    {
        x = a;
    }
};

int main()
{
    Number a(10);
    a.display();
}