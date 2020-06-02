#include <iostream>

using namespace std;

class Country
{
    string name;
    int area, population;
    float populationDensity;

public:
    Country(string cName, float cArea, int cPop)
    {
        name = cName;
        area = cArea;
        population = cPop;
        populationDensity = cPop / cArea;
    }

    Country *maxPop(Country *arr[], int len)
    {
        int index = 0, max_pop = 0;
        for (int i = 0; i < len; i++)
        {
            if (arr[i]->population > max_pop)
            {
                index = i;
                max_pop = arr[i]->population;
            }
        }
        return arr[index];
    }

    Country *maxArea(Country *arr[], int len)
    {
        int index = 0, max_area = 0;
        for (int i = 0; i < len; i++)
        {
            if (arr[i]->area > max_area)
            {
                index = i;
                max_area = arr[i]->area;
            }
        }
        return arr[index];
    }

    Country *maxDensity(Country *arr[], int len)
    {
        int index = 0;
        float popDen = 0;
        for (int i = 0; i < len; i++)
        {
            if (arr[i]->populationDensity > popDen)
            {
                index = i;
                popDen = arr[i]->populationDensity;
            }
        }
        return arr[index];
    }

    void Display()
    {
        cout << "\nCountry Name : " << name << "\nArea : " << area;
        cout << "\nPopulation : " << population << "\nDensity : " << populationDensity;
    }
};

int main()
{
    int n;
    cout << "Enter the no. of countries : ";
    cin >> n;
    if (n < 1)
    {
        cout << "Error!! Invalid Array size";
        exit(0);
    }
    Country *arr[n];
    for (int i = 0; i < n; i++)
    {
        string name;
        int area, population;
        cout << "Enter the Country's Name : ";
        getline(cin, name);
        cin.ignore();
        cout << "Enter the Country's Area : ";
        cin >> area;
        cout << "Enter the Country's Population : ";
        cin >> population;
        static Country a(name, area, population);
        arr[i] = &a;
    }
    cout << "\nCountry with maximum Area : \n";
    arr[0]->maxArea(arr, n)->Display();
    cout << "\nCountry with maximum Population : \n";
    arr[0]->maxPop(arr, n)->Display();
    cout << "\nCountry with maximum Population Density : \n";
    arr[0]->maxDensity(arr, n)->Display();
    return 0;
}