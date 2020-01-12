#include <iostream>

using namespace std;

class Pensioner
{
    string name;
    char gender;
    int age, socialSecurityNumber, pensionAmount;

public:
    void getdata();
    bool isEligible();
    void print();
};

void Pensioner::getdata()
{
    cout << "\nEnter the Pensioner's Name : ";
    cin.sync();
    getline(cin, name);
    cout << "\nEnter the gender : ";
    cin.sync();
    cin >> gender;
    cout << "\nEnter the age : ";
    cin >> age;
    cout << "\nEnter the Social Security Number : ";
    cin >> socialSecurityNumber;
    cout << "\nEnter the Pension Amount : ";
    cin >> pensionAmount;
}

bool Pensioner::isEligible()
{
    if (pensionAmount < 1500)
    {
        bool ch;
        cout << "\nDoes the Pensioner get Financial Assistance from his/her offsprings? (yes-1/no-0)";
        cin >> ch;
        if (ch)
            return true;
        else
            return false;
    }
    else
        return false;
}

void Pensioner::print()
{
    cout << "\nName : " << name << "\nAge : " << age << "\nGender : " << gender 
        << "\nSocial Security Number : " << socialSecurityNumber << "\n Pension Amount : " << pensionAmount;
}