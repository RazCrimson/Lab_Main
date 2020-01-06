#include <iostream>
#include <string.h>
using namespace std;

struct Dictionary
{
    char *term;
    char *meaning;
    void read();
    void display();
};

void Dictionary::read()
{
    term = new char[10];
    meaning = new char[100];
    cout << "Enter the term: ";
    cin >> term;
    cout << "Enter the meaning:\n";
    cin >> meaning;
}

void Dictionary::display()
{
    cout << "The term is " << term << endl;
    cout << "The meaning is " << meaning << endl;
}

void search(Dictionary *D, char *Term)
{
    bool found = false;
    short int i;
    for (i = 0; i < 5; i++)
    {
        if (strcmp(D[i].term, Term) == 0)
        {
            found = true;
            cout << "The meaning of " << D[i].term << " is " << D[i].meaning << endl;
            break;
        }
    }
    if (found == false)
        cout << "The term is not found\n";
}

int main()
{
    char *term = new char[10];
    short int i;
    Dictionary D[5];
    cout << "Enter 5 terms and their meanings:\n";
    for (i = 0; i < 5; i++)
        D[i].read();
    cout << "Enter the term to be searched for: ";
    cin >> term;
    search(D, term);
    cout << "The terms and their meanings are:\n";
    for (i = 0; i < 5; i++)
        D[i].display();
}
