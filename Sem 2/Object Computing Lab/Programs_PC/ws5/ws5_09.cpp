#include <iostream>

using namespace std;

class Computer
{
    int memorySize;
    string processorName, networkAddress;

public:
    Computer(string processorName, int memorySize, string networkAddress = "")
    {
        this->processorName = processorName;
        this->memorySize = memorySize;
        this->networkAddress = networkAddress;
        cout << "Comp\n";
    }
    friend bool isNetworkAssigned(const Computer &);
};

bool isNetworkAssigned(const Computer &computer)
{
    if (computer.networkAddress != "")
        return true;
    return false;
}

class Laptop : virtual public Computer
{
    int weight;

public:
    Laptop(string processorName, int memorySize, int weight, string networkAddress = "")
        : Computer(processorName, memorySize, networkAddress)
    {
        cout << "Lap\n";
        this->weight = weight;
    }
};

class Palmtop : virtual public Computer, public Laptop
{
    int height, width;

public:
    Palmtop(string processorName, int memorySize, int weight, int height, int width, string networkAddress = "")
        : Computer(processorName, memorySize, networkAddress), Laptop(processorName, memorySize, weight, networkAddress)
    {
        cout << "Palm\n";
        this->height = height;
        this->width = width;
    }
};

int main()
{
    Palmtop a("pName", 1000, 10, 10, 10, "123");
    cout << isNetworkAssigned(a);
}