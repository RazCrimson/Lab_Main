#include <iostream>

using namespace std;

class Set
{
    int *ptr;
    int length;
    public:
        Set(int);
        bool add(int);
        bool remove(int);
        Set operator |(Set &);
        Set operator &(Set &);
};

Set::Set(int n)
{
    ptr = new int[n]();
  
    length = n;
}

bool Set::add(int x)
{
    for(int i = 0; i < length; i++)
    {
        if(ptr[i] == x)
            return true;
    }
}