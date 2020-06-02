#include <iostream>

using namespace std;

class Base
{
protected:
    unsigned i;

public:
    Base()
    {
        i = 0;
    }
    void display()
    {
        cout << i;
    }
};

class Derived : protected Base
{
public:
    Base::i;
    int j;
    Derived()
    {
        j = 1;
    }
    void display()
    {
        display();
        cout << j;
    }
};

int main()
{
    Derived d;
    cout << d.i;
}