#include <iostream>

using namespace std;

class Worker
{
protected:
    string name;
    float salaryRate;

public:
    Worker(string name, float salaryRate);
    virtual double computePay(int) = 0;
};

Worker::Worker(string name, float salaryRate)
{
    this->name = name;
    this->salaryRate = salaryRate;
}

class HourlyWorker : public Worker
{
public:
    HourlyWorker(string name, float salaryRate) : Worker(name, salaryRate) {}
    double computePay(int);
};

double HourlyWorker::computePay(int hours)
{
    double pay = 0;
    if (hours > 40)
    {
        pay = 1.5 * salaryRate * (hours - 40);
        hours = 40;
    }
    pay += hours * salaryRate;
    return pay;
}

class SalariedWorker : public Worker
{
public:
    SalariedWorker(string name, float salaryRate) : Worker(name, salaryRate) {}
    double computePay(int hours)
    {
        return 40 * salaryRate;
    }
};

int main()
{
    bool type;
    int hours;
    string name;
    float salaryRate;
    Worker *ptr = NULL;
    do
    {
        cout << "\nEnter the Worker's Name : ";
        getline(cin, name);
        cout << "\nEnter the Worker's Salary Rate : ";
        cin >> salaryRate;
        cout << "\nEnter the type of worker (0 - Hourly / 1 - Salarised) : ";
        cin >> type;
        if (type)
            ptr = new HourlyWorker(name, salaryRate);
        else
            ptr = new SalariedWorker(name, salaryRate);
        cout << "\nEnter the number of Hours worked : ";
        cin >>hours;
        cout << "\nSalary of the Worker is  : "<<ptr->computePay(hours);
        cout << "Do you want a continue ? (0 - No / 1 - Yes) : ";
        cin >> type;
        if(!hours)
            break;
    }while(true);
    return 0;
}