#include <iostream>

using namespace std;

class Population
{
    int units_on_hand;
    double price;
    string description;

public:
    Population(int units, string &des, double pri);
    void setPrice(double);
    void setDescription(string &);
    void setUnitsOnHand(int);
    string getDescription();
    double getPrice();
    int getUnitsOnHand();
};

Population::Population(int units, string &des, double pri)
{
    setPrice(pri);
    setDescription(des);
    setUnitsOnHand(units);
}

void Population::setPrice(double pri)
{
    price = pri;
}

void Population::setDescription(string &des)
{
    description = des;
}

void Population::setUnitsOnHand(int units)
{
    units_on_hand = units;
}

string Population::getDescription()
{
    return description;
}

double Population::getPrice()
{
    return price;
}

int Population::getUnitsOnHand()
{
    return units_on_hand;
}

int main()
{
    Population **arr = new Population *[3];
    for (int i = 1; i <= 3; i++)
    {
        string des;
        int units;
        double pri;
        cout << "Enter the Price of Item " << i << '\0';
        cin >> pri;
        cout << "Enter the No. of Units of Item " << i << '\0';
        cin >> units;
        cout << "Enter the Description of Item " << i << '\0';
        cin.sync();
        getline(cin, des);
        arr[i - 1] = new Population(units, des, pri);
    }
}