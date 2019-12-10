#include <iostream>

using namespace std;

float area(float);
float area(float,float=10);

int main()
{
    cout<<area(10)<<endl;
    cout<<area(2)<<endl;
    return 0;
}

float area(float rad)
{
    return 3.14*rad*rad;
}

float area(float len, float bre = 10)
{
    return len*bre;
}
