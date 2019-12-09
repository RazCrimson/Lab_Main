#include <iostream>
#include <cstdlib>

using namespace std;


int OddEven(int *arr,int len)
{

}

void even_replace(int* arr,int len)
{
    int y;
    cout<<"Enter the value of y : ";
    cin>>y;
    for(int i=0;i<len;i+=2)
        arr[i]=y;
}



int main()
{
    int len = 0,item, sum=0,avg=0,pos=0,neg=0;
    cout << "Enter the No. of Elements : ";
    cin >> len;
    if (len <= 0)
    {
        cout << "Warning!!! Invalid Index" << endl;
        exit(0);
    }
    int *arr = (int *)malloc(sizeof(int) * len);
    cout << "Enter the Elements of the Array :\n";
    for (int i = 0; i < len; i++)
    {
        cin >> item;
        arr[i]=item;
        sum+=item;
        if(item > 0)
            pos++;
        else if(item<0)
            neg++;
    }
    avg=sum/len;
    cout<<"\nSum : "<<sum<<"\nAverage : "<<avg<<"\nPositive Numbers : "<<pos<<"\nNegative Numbers : "<<neg;
    while (1)
    {
        cout<<"1.Check if a number is present in the list\n2.Replace even index elements by a number.\n";
        cout<<"3.Read a number and search the list\nEnter your choice : ";
    }

}