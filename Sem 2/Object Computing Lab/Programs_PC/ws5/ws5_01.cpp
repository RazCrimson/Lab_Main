#include<iostream>
using namespace std;

class Publications
{
    protected:
        string title;
        float price;
    public:
        void getData();
        void putData(); 

};

class Book : public Publications
{
    int pageCount;
    public:
        void getData();
        void putData();
};

class Tape : public Publications
{
    float playTime;
    public:
        void getData();
        void putData();
}; 

void Publications::getData()
{
    cin.sync();
    cout << "Enter the title: ";
    cin >> title;
    cout << "Enter the price: ";
    cin >> price;
}

void Publications::putData()
{
    cout << "The title is: " << title << endl;
    cout << "The price is: " << price << endl;
}

void Book::getData()
{
    Publications::getData();
    cout << "Enter the page count: ";
    cin >> pageCount;
}

void Book::putData()
{
    Publications::putData();
    cout << "The page count is: " << pageCount << endl;
}

void Tape::getData()
{
    Publications::getData();
    cout << "Enter the play time: ";
    cin >> playTime;
}

void Tape::putData()
{
    Publications::putData();
    cout << "The play time is: " << playTime << endl;
}

int main()
{
    Book B;
    Tape T;
    B.getData();
    T.getData();
    B.putData();
    T.putData();
}