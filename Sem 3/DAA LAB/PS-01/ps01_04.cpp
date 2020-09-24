#include <iostream>
#include "BST.hpp"

using namespace std;

int main()
{    BST<int> bst;
    bst.insertIntoTree(0x50);
    bst.insertIntoTree(0x30);
    bst.insertIntoTree(0x20);
    bst.insertIntoTree(0x40);
    bst.insertIntoTree(0x70);
    bst.insertIntoTree(0x60);
    bst.insertIntoTree(0x80);
    bst.insertIntoTree(0x90);
    bst.insertIntoTree(0x10);

    cout<< "\nTree :\n";
    bst.printAllLevels();
    
    return 0;
}