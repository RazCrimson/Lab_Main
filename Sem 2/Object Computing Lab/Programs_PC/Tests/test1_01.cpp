#include <iostream>

using namespace std;

void func(char = '*', int = 10);

int main()
{
    func(5);
    return 0;
}

void func(char ch = '*', int n = 10)
{
    for (int i = 0; i < n; i++)
        cout << ch << endl;
}