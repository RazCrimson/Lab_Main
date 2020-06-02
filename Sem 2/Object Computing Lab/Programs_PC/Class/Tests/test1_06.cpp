#include <iostream>

using namespace std;

class Example
{
private:
    int number;

public:
    Example() { number = 10; }
};

int main()
{
    Example ex;
    int *x = (int*)&ex;
    cout << *x;
}