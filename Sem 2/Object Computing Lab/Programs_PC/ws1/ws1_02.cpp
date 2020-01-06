#include <iostream>
using namespace std;

struct Program
{
    long linOfCode;
    int noOfFun;
    int libraries;
};

void checkProgram(Program);
void readProgram(Program *);
void displayProgram(Program);

int main()
{
    Program prog[10];
    int i;
    cout << "Enter 10 program details:\n";
    for (i = 0; i < 10; i++)
    {
        cout << "Enter details of program " << i + 1 << endl;
        readProgram(&prog[i]);
    }
    cout << "The program details are:\n";
    for (i = 0; i < 10; i++)
    {
        cout << "The details of program " << i + 1 << endl;
        displayProgram(prog[i]);
    }
    for (i = 0; i < 10; i++)
    {
        cout << "The info about program " << i + 1 << endl;
        checkProgram(prog[i]);
    }
}

void readProgram(Program *p)
{
    cout << "Enter the number of lines of code: ";
    cin >> p->linOfCode;
    cout << "Enter the number of functions: ";
    cin >> p->noOfFun;
    cout << "Enter the number of libraries: ";
    cin >> p->libraries;
}

void displayProgram(Program p)
{
    cout << "The number of lines of code are " << p.linOfCode << endl;
    cout << "The number of functions are " << p.noOfFun << endl;
    cout << "The number of libraries are " << p.libraries << endl;
}

void checkProgram(Program p)
{
    if (p.libraries >= 10 && p.noOfFun >= 100 && p.linOfCode >= 1000000)
        cout << "It is a Software\n";
    else if (p.libraries >= 1 && p.noOfFun >= 50 && p.linOfCode >= 1000)
        cout << "It is a Package\n";
    else
        cout << "It is a Header file";
}