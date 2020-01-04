#include <iostream>

using namespace std;
template <typename T>

class Maximum
{
    T a,b,c;
public:
    Maximum(T x, T y,T z)
    {
        a=x;
        b=y;
        c=z;
    }

    T max()
    {
        if(a>b && a>c)
            return a;
        else if(b>a && b>c)
            return b;
        else
            return c;
    }
    
};
