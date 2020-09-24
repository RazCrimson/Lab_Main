#include <iostream>
#include "BST.hpp"

using namespace std;

int main()
{
    BST<int> bst;
    int counter = 0, temp;

    cout << "Please enter the value of N: ";
    cin >> counter;

    for (int i = 0; i < counter; i++)
    {
        cin >> temp;
        bst.insertIntoTree(temp);
    }
    cout << "\nTree :\n";
    bst.printTreeL2R();

    cout << "Please enter the value of X: ";
    cin >> counter;

    temp = bst.numberOfNodesInTree();

    if (temp == counter)
        cout << "Good" << endl;
    else if (temp > counter)
        cout << "Average" << endl;
    else
        cout << "Bad" << endl;

    return 0;
}
