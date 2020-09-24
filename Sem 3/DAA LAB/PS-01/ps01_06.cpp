#include <iostream>
#include "BST.hpp"

using namespace std;

int main()
{
    BST<int> bst;
    int counter = 0, temp;

    cout << "Please enter the Number of elements in array: ";
    cin >> counter;

    for (int i = 0; i < counter; i++)
    {
        cin >> temp;
        bst.insertIntoTree(temp);
    }
    cout << "\nTree :\n";
    bst.printTreeL2R();

    cout << "Height of the tree is  " << bst.heightOfTree() << endl;
    return 0;
}
