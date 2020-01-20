#include <iostream>

using namespace std;

class Population
{
    int population, numberOfBirths, numberOfDeaths;

public:
    Population(int pop, int births, int deaths);
    double getBirthRate();
    double getDeathRate();
};

Population::Population(int pop, int births, int deaths)
{
    if (pop < 1 || births < 0 || deaths < 0)
    {
        cout << "Invalid Values!\n";
        delete this;
        return;
    }
    population = pop;
    numberOfBirths = births;
    numberOfDeaths = deaths;
}

double Population::getBirthRate()
{
    return float(numberOfBirths) / population;
}

double Population::getDeathRate()
{
    return float(numberOfDeaths) / population;
}

int main()
{
    int pop, births, deaths;
    cout << "\nEnter the population  :";
    cin >> pop;
    cout << "\nEnter the Number of Births :";
    cin >> births;
    cout << "\nEnter the Number of Deaths :";
    cin >> deaths;
    Population a(pop, births, deaths);
    cout << "\nThe Birth and death rates are : " << a.getBirthRate() << " and  " << a.getDeathRate();
}