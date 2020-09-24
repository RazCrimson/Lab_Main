#include <iostream>
#include "BST.hpp"

using namespace std;

int main()
{
    BST<int> bst;
    int n, m, temp;
    n = m = temp = 0;
    
    cout << "Enter the number of students in the class: ";
    cin >> n;

    cout << "Enter the number of students who are yet to come: ";
    cin >> m; 

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the number of Candles with " << i + 1 << "th student : ";
        cin >> temp;
        bst.insertIntoTree(temp);
    }
    cout << "\nStudent Tree :\n";
    bst.printTreeL2R();

    for (int i = 0; i < m; i++)
    {
        cout << "Enter the number of Candles with the " << i + 1<< "th student who came : ";
        cin >> temp;
        if(bst.findNodeWithValue(temp))
            cout << "Monk: YES\n";
        else
            cout << "Monk: NO\n";
    }

    return 0;
}