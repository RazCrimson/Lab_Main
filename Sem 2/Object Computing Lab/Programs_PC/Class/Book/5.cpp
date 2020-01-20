#include <iostream>

using namespace std;

class RetailItem
{
    int units_on_hand;
    double price;
    string description;

public:
    RetailItem(int units, string &des, double pri);
    void setPrice(double);
    void setDescription(string &);
    void setUnitsOnHand(int);
    string getDescription();
    double getPrice();
    int getUnitsOnHand();
};

RetailItem::RetailItem(int units, string &des, double pri)
{
    setPrice(pri);
    setDescription(des);
    setUnitsOnHand(units);
}

void RetailItem::setPrice(double pri)
{
    price = pri;
}

void RetailItem::setDescription(string &des)
{
    description = des;
}

void RetailItem::setUnitsOnHand(int units)
{
    units_on_hand = units;
}

string RetailItem::getDescription()
{
    return description;
}

double RetailItem::getPrice()
{
    return price;
}

int RetailItem::getUnitsOnHand()
{
    return units_on_hand;
}

int main()
{
    RetailItem **arr = new RetailItem *[3];
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
        arr[i - 1] = new RetailItem(units, des, pri);
    }
}