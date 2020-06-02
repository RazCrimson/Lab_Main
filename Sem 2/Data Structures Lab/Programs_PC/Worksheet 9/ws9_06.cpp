#include <iostream>
#include "SinglyLinked.hpp"

using namespace std;

int main()
{
    int n, temp;
    cout << "Enter the Number of Nodes : ";
    cin >> n;
    SinglyLinked<int> *ptr = new SinglyLinked<int>[n]();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            if (temp == 1)
                ptr[i].insertEnd(j);
        }
    }
    for (int i = 0; i < n; i++)
    {
        ptr[i].display();
        cout << endl;
    }
    return 0;
}