#include <iostream>
using namespace std;

class Meal
{
    string name;
    int calorie;
    Meal() { name = ""; calorie = 0;}
    Meal( string name, int calorie) { this->name = name; this->calorie = calorie; }
    friend ostream& operator << (ostream& , Meal&);
    friend istream& operator >> (istream& , Meal&);
    Meal operator + (const Meal&);
};

ostream& operator << (ostream &out, Meal &meal)
{
    out << "The name of the meal is: " << meal.name << endl;
    out << "The calorie count is: " << meal.calorie << endl;
    return out;
}

istream& operator >> (istream &in, Meal &meal)
{
    cin.sync();
    cout << "Enter the meal name: ";
    in >> meal.name;
    cout << "Enter the calorie count: ";
    in >> meal.calorie;
    return in;
}

Meal Meal::operator + (const Meal &meal)
{
    return { "Daily Total", calorie + meal.calorie }; 
}