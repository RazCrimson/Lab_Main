#include <iostream>

using namespace std;

class Donor{
    char* name;
    int area,population;
    float populationDensity;
public:
    Donor(char* cName,float cArea,int cPop){
        name = cName;
        area = cArea;
        population = cPop;
        populationDensity = cPop/cArea;
    }

    Donor maxPop(Donor arr[],int len)
    {
        Donor Pop("",0,0);
        for(int i=0;i<len;i++)
        {
            if(arr[i].population > Pop.population)
                Pop = arr[i];
        }
        return Pop;
    }

    Donor maxArea(Donor arr[],int len)
    {
        Donor Area("",0,0);
        for(int i=0;i<len;i++)
        {
            if(arr[i].area > Area.area)
                Area = arr[i];
        }
        return Area;
    }

    Donor maxDensity(Donor arr[],int len)
    {
        Donor Dense("",0,0);
        for(int i=0;i<len;i++)
        {
            if(arr[i].area > Dense.population)
                Dense = arr[i];
        }
        return Dense;
    }
};



int main()
{

}