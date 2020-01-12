#include <iostream>
#include <string>
using namespace std;

int noOfEmpplayees = 0;

class Employee
{
    string name, designation, locationOfWorkplace;
    int employeeNumber, basicPay;

public:
    Employee();
    Employee(Employee &);
    ~Employee();
    void display();
    bool match(string, string);
    void operator=(Employee);
};

Employee::Employee()
{
    cout << "\nEnter the Name of the Employee : ";
    cin.sync();
    getline(cin, name);
    cout << "\nEnter the Employee Number : ";
    cin >> employeeNumber;
    cout << "\nEnter the Designation : ";
    cin.sync();
    getline(cin, designation);
    cout << "\nEnter the Location of the Workplace : ";
    cin.sync();
    getline(cin, locationOfWorkplace);
    cout << "\nEnter the Employee's Basic Pay : ";
    cin >> basicPay;
    noOfEmpplayees += 1;
}

Employee::~Employee()
{
    noOfEmpplayees -= 1;
}

Employee::Employee(Employee &b)
{
    cout << "\nError: Emplayee details can't be copied!";
    delete this;
}

void Employee::operator=(Employee b)
{
    cout << "\nError: Emplayee details can't be copied!";
    delete this;
}

void Employee::display()
{
    cout << "\nName : " << name << "\nEmployee Number : " << employeeNumber << "\nDesignation : " << designation
         << "\nLocationh of Workplace : " << locationOfWorkplace << "\nBasicPay : " << basicPay;
}

bool Employee::match(string qName, string qlocation)
{
    if (qName == name && qlocation == locationOfWorkplace)
        return true;
    else
        return false;
}