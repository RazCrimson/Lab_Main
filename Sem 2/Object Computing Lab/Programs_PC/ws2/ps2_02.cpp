
#include <iostream>

using namespace std;

int tripleByValue(int n);
void tripleByReference(int &n);
void tripleByAddress(int* n);

int main()
{
    int n;
    cout<<"Enter the value : ";
    cin>>n;
    cout<<"By Value : "<<tripleByValue(n)<<endl;
    tripleByReference(n);
    cout<<"By Reference : "<<n<<endl;
    tripleByAddress(&n);
    cout<<"By Address : "<<n<<endl;
    return 0;
}

void tripleByAddress(int* n)
{
    *n *=3;
}

void tripleByReference(int &n)
{
    n *=3;
}

int tripleByValue(int n)
{
    return 3*n;
}