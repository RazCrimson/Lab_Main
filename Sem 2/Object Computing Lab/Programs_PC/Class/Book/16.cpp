#include <iostream>

using namespace  std;

class temperature
{
    double temp;
public:
    void read(double);
    bool isEthylFreezing();
    bool isOxygenFreezing();
    bool isWaterFreezing();
    bool isEthylBoiling();
    bool isOxygenBoiling();
    bool isWaterBoiling();
};

void temperature::read(double t)
{
    temp = t;
}

bool temperature::isEthylBoiling(){
    if( temp >= 172)
        return true;
    else
        return false;
}

bool temperature::isOxygenBoiling(){
    if( temp >= -306)
        return true;
    else
        return false;
}

bool temperature::isWaterBoiling(){
    if( temp >= 212)
        return true;
    else
        return false;
}

bool temperature::isEthylFreezing(){
    if( temp <= -173)
        return true;
    else
        return false;
}

bool temperature::isOxygenFreezing(){
    if( temp <= -362)
        return true;
    else
        return false;
}

bool temperature::isWaterFreezing(){
    if( temp <= 32)
        return true;
    else
        return false;
}


int main()
{
    temperature obj;
    double temp;
    cout << "Enter the temperature : ";
    cin >> temp;
    obj.read(temp);
    cout << "Boiling : \n";
    if(obj.isEthylBoiling())
        cout<<"Ethyl\n";
    if(obj.isOxygenBoiling())
        cout<<"Oxygen\n";
    if(obj.isWaterBoiling())
        cout<<"Water\n";
    cout << "Freezing : \n";
    if(obj.isEthylFreezing())
        cout<<"Ethyl\n";
    if(obj.isOxygenFreezing())
        cout<<"Oxygen\n";
    if(obj.isWaterFreezing())
        cout<<"Water\n";
    return 0;
}