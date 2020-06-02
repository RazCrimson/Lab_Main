#include <iostream>

using namespace std;
template <typename T>

class Power
{
    T x;

public:
    Power(T a)
    {
        x = a;
    }

    T result(T y = 0)
    {
        T var = 1;
        for (T i = 0; i < y; i++)
            var *= x;
        return var;
    }
};
