#include <iostream>
#include <cstdlib>

using namespace std;


int main()
{
    int arr[50]={0},temp;
    cout<<"Enter the elements of the array : ";
    for(int i=0;i<500;i++)
    {
        cin>>temp;
        if(temp>100||temp<0)
        {
            cout<<"Error!! Invalid Number";
            exit(0);
        }
        if(temp> 50)
            arr[temp-51]++;
    }
    for(int i =0;i<50;i++)
        cout<<i+51<<" occured "<<arr[i]<<" times\n";
    return 0;
}
