#include <iostream>

using namespace std;

template <typename T>
T fibonacci(T n)
{
    T a = -1, b = 1, c = 0;
    for (T i = 0; i < n; i++)
    {
        c = a + b;
        cout << c << "\t";
        a = b;
        b = c;
    }
    cout << endl;
    return c;
}

int main()
{
    fibonacci<int>(10);
    fibonacci<float>(10.5135);
    fibonacci<long>(100);
    fibonacci<char>('1');
}
