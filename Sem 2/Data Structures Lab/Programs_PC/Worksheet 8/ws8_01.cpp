#include <iostream>
#include "SinglyLinked.hpp"

int main()
{
    int ch, select = 0, element;
    SinglyLinked<int> list[6];

    while (1)
    {
        cout << "1) Append an element to the end of a list\n"
                "2) Concatenate two lists\n"
                "3) Free all the nodes in a list\n"
                "4) Reverse a list, so that the last element becomes the first, and so on. \n"
                "5) Delete the last element from a list\n"
                "6) Delete the nth element from a list\n"
                "7) Combine two ordered lists into a single ordered list\n"
                "8) Form a list containing the union of the elements of two lists\n"
                "9) Form a list containing the intersection of the elements of two lists\n"
                "10) Insert an element after the nth element of a list\n"
                "11) Delete every second element from a list\n"
                "12) Place the elements of a list in increasing order\n"
                "13) Return the sum of the integers in a list\n"
                "14) Return the number of elements in a list\n"
                "15) Move node(p) forward n positions in a list\n"
                "16) Make a second copy of a list \n";

        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Select the list : ";
            cin >> select;
            cout << "Append an element to the end of a list: ";
            cin >> element;
            list[select % 6].append(element);
            break;
        case 2:
            list[0].concatenate(list[1]);
            break;
        case 3:
            cout << "Select the list : ";
            cin >> select;
            list[select % 6].free();
            break;
        case 4:
            cout << "Select the list : ";
            cin >> select;
            list[select % 6].reverse();
            break;
        case 5:
            cout << "Select the list : ";
            cin >> select;
            list[select % 6].deleteEnd();
            break;
        case 6:
            cout << "Select the list : ";
            cin >> select;
            cout << "Enter the value of n: ";
            cin >> element;
            list[select % 6].deleteNth(element);
            break;
        case 7:
            list[3] = list[0].combine(list[1]);
            break;
        case 8:
            list[4] = list[0].set(list[1]);
            break;
        case 9:
            list[5] = list[0].intersection(list[1]);
            break;
        case 10:
            int data;
            cout << "Select the list : ";
            cin >> select;
            cout << "Enter the value of n: ";
            cin >> element;
            cout << "Enter the value of data ";
            cin >> data;
            list[select % 6].insertAfterNth(element, data);
            break;
        case 11:
            cout << "Select the list : ";
            cin >> select;
            cout << "Enter the value of n: ";
            cin >> element;
            list[select % 6].delete_every_nth(element);
            break;
        case 12:
            cout << "Select the list : ";
            cin >> select;
            list[select % 6].sort();
            break;
        case 13:
            cout << "Select the list : ";
            cin >> select;
            cout << "\nThe sum is : " << list[select % 6].sum();
            break;
        case 14:
            cout << "Select the list : ";
            cin >> select;
            cout << "\nThe Number of elements is : " << list[select % 6].numberOfElements();
            break;
        case 15:
            cout << "Select the list : ";
            cin >> select;
            int p, n;
            cout << "Enter the element postion and the no. of positions to move forward : ";
            cin >> p >> n;
            list[select % 6].moveNode(p, n);
            break;
        case 16:
            cout << "Select the list : ";
            cin >> select;
            list[5] = list[select % 6];
        case 0:
            cout << "Select the list : ";
            cin >> select;
            list[select % 6].display();
            break;
        default:
            return 0;
        }
    }
}