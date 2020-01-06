#include <iostream>
#include <limits>
#include <string>
using namespace std;

struct Vehicle
{
    int regNo;
    string manName;
    int yearOfMake;
    string model;
    int type;
    string colour;
};

void read(Vehicle *);
void display(Vehicle);

int main()
{
    string manName;
    bool flag = 0;
    int i, year, regNo;
    Vehicle v[10];
    cout << "Enter the details of 10 vehicles:\n";
    for (i = 0; i < 10; i++)
    {
        cout << "Enter the details of vehicle " << i + 1 << endl;
        read(&v[i]);
    }
    cout << "Enter the year to be searched for: ";
    cin >> year;
    cout << "The details of vehicles with given year as year of manufacturing are:\n";
    for (i = 0; i < 10; i++)
    {
        if (v[i].yearOfMake == year)
        {
            flag = 1;
            cout << "Vehicle " << i + 1 << endl;
            display(v[i]);
        }
    }
    if (!flag)
        cout << "There are no vehicles with the given year as year of manufacturing\n";
    flag = 0;
    cout << "Enter the manufacturer name: ";
    cin.sync();
    getline(cin, manName);
    cout << "The details of vehicles with given manufacturer name:\n";
    for (i = 0; i < 10; i++)
    {
        if (manName.compare(v[i].manName) == 0)
        {
            flag = 1;
            cout << "Vehicle " << i + 1 << endl;
            display(v[i]);
        }
    }
    if (!flag)
        cout << "There are no vehicles with the given manufacturer name\n";
    flag = 0;
    cout << "Enter the registration number to be searched for: ";
    cin >> regNo;
    cout << "The details of vehicles with given number as registration number are:\n";
    for (i = 0; i < 10; i++)
    {
        if (v[i].regNo == regNo)
        {
            flag = 1;
            cout << "Vehicle " << i + 1 << endl;
            display(v[i]);
        }
    }
    if (!flag)
        cout << "There are no vehicles with the given registration number\n";
}
void read(Vehicle *v)
{
    cout << "Enter the registration number: ";
    cin >> v->regNo;
    cout << "Enter the manufacturer name: ";
    cin.sync();
    getline(cin, v->manName);
    cout << "Enter the year of manufacture: ";
    cin >> v->yearOfMake;
    cout << "Enter the model: ";
    cin.sync();
    getline(cin, v->model);
    cout << "Enter the type of vehicle (No. of wheels): ";
    cin >> v->type;
    cout << "Enter the colour of the vehicle: ";
    cin.sync();
    getline(cin, v->colour);
}

void display(Vehicle v)
{
    cout << "The registration number is: " << v.regNo << endl;
    cout << "The manufacturer name is: " << v.manName << endl;
    cout << "The year of manufacture is: " << v.yearOfMake << endl;
    cout << "The model is: " << v.model << endl;
    cout << "The type of vehicle is: " << v.type << " wheeler\n";
    cout << "The colour of vehicle is: " << v.colour << endl;
}