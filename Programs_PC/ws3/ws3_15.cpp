#include <iostream>
#include <stdlib.h>

int main()
{
    unsigned short Input;
    cout<<"\nEnter the Input : ";
    cin>>Input;
    if(Input>=100&&Input<=999)
    {
        if((Input-((Input%10)+((int)(Input/100)*100)==((Input%10)+(Input/100))
            cout<<"\nThe Middle Digit is the sum of the other two digits";
        else
        {
            cout<<"\nThe Middle Digit is not the sum of the other two digits";
        }
    }
    else
    {
        cout<<"\nERROR!\nEnter a three digit number";
        exit(7);
    }
    cout<<endl;
    return 0;
}