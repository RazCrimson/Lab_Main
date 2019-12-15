#include <iostream>

using namespace std;

float area(float);
float area(float,float);

int main()
{
    cout<<area(10)<<endl;
    cout<<area(2.5f)<<endl<<sizeof(wchar_t);
    return 0;
}

float area(float rad)
{
    return 3.14*rad*rad;
}

float area(float len, float bre)
{
    return len*bre;
}
