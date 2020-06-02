#include<iostream>
using namespace std;

class PhoneCall
{
    int phoneNo;
    float lengthOfCall;
    float ratePerMin;
    public:
        friend ostream& operator << (ostream& , PhoneCall&);
        friend istream& operator >> (istream& , PhoneCall&);
        bool operator == (const PhoneCall&);      
};

ostream& operator << (ostream &out, PhoneCall &P)
{
    out << "Phone Number: " << P.phoneNo << endl;
    out << "Length of call: " << P.lengthOfCall << " minutes" << endl;
    out << "Rate per minute: " << P.ratePerMin << endl;
    return out;
}

istream& operator >> (istream &in, PhoneCall &P)
{
    cin.sync();
    cout << "Enter the Phone number: ";
    in >> P.phoneNo;
    cout << "Enter the Length of call(in min): ";
    in >> P.lengthOfCall;
    cout << "Enter the rate per minute: ";
    in >> P.ratePerMin;
    return in;
}

bool PhoneCall::operator == (const PhoneCall& P)
{
    if(this->phoneNo == P.phoneNo)
        return true;
    else
        return false;
}

int main()
{
    PhoneCall arr[10];
    cout << "Enter the details of the phone call: \n";
    for(int i = 0; i < 10; i++)
    {
        cout << "Enter the details of phonecall: " << i + 1 << endl;
        cin >> arr[i];
        for(int j = i-1; j >= 0; j--)
        {
            if(arr[i] == arr[j])
            {
                cout << "Call placed already\n";
                i--;
                break;
            }
        }
    }
}