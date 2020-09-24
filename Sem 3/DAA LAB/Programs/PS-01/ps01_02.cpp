#include <iostream>
#include "BST.hpp"

using namespace std;

int main()
{
    int counter = 0;
    BST<int> bst;
    bst.insertIntoTree(1);
    bst.insertIntoTree(2);
    bst.insertIntoTree(3);
    bst.insertIntoTree(4);
    bst.insertIntoTree(5);
    bst.insertIntoTree(6);
    bst.insertIntoTree(7);
    bst.insertIntoTree(8);
    bst.insertIntoTree(9);
    bst.insertIntoTree(10);

    cout<< "\nTree :\n";
    bst.printTreeL2R();

    bst.findNodeWithValue(10, &counter);

    cout << "Number of checks to find 10 is " << counter << endl;
    return 0;
}
