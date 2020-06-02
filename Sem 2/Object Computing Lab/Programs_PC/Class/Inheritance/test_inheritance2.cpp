#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void eat()
    {
        cout << "Generic food\n";
    }
};

class Cat : public Animal
{
public:
    void eat()
    {
        cout << "I eat Rats\n";
    }
};

int main()
{
    Animal *ptr = new Animal;
    Cat *c = new Cat;
    ptr = c;
    ptr->eat();
    c->eat();
}