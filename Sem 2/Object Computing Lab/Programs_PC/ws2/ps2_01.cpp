#include <iostream>

using namespace std;

int funCircleArea(float radius);

int main()
{
    float n;
    cout<<"Enter the value of Radius : ";
    cin>>n;
    cout<<funCircleArea(n);
    return 0;
}

int funCircleArea(float radius)
{
    return 3.14*radius*radius; 
}