#include <iostream>

using namespace std;

class Student
{
    string name;
    float marks;

public:
    int get_marks();
    void read();
    void print();
};

void Student::read()
{
    cout << "\nEnter the name : ";
    cin >> name;
    cout << "Enter the marks : ";
    cin >> marks;
}
void Student::print()
{
    cout << "\nName : " << name << "\nMarks : " << marks;
}

float average(Student arr[], int len)
{
    float res;
    for (int i = 0; i < len; i++)
        res += arr[i].get_marks;
    res /= len;
    return res;
}

int main()
{
    Student S1[10];
    for (int i = 0; i < 10; i++)
        S1[i].read();
    cout << "\nAverage : " << average(S1, 10);
    return 0;
}