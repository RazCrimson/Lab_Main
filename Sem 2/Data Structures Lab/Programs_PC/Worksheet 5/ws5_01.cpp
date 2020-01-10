#include <iostream>
#include "Stack.hpp"

int main()
{
    Stack s1;
    int size, ch, element;
    cout << "Enter the max size of Stack : ";
    cin>>size;
    s1.assignSize(size);
    while (size > 0)
    {
        cout << "\n\nStack Menu\n"
             << "1.Push\n2.Pop\n3.Count\n"
             << "4.Display from bottom\n"
             << "5.Display from top\n"
             << "Other to quit\n"
             << "Enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter the element : ";
            cin >> element;
            try
            {
                s1.push(element);
            }
            catch (const std::exception &e)
            {
                cout << e.what() << '\n';
            }
            break;
        case 2:
            try
            {
                cout<<"The element is " << s1.pop();
            }
            catch (const std::exception &e)
            {
                cout << e.what() << '\n';
            }
            break;
        case 3:
            cout << "The count is " << s1.count();
            break;
        case 4:
            s1.displayFromBottom();
            break;
        case 5:
            s1.displayFromTop();
            break;
        default:
            size = 0;
        }
    }
    return 0;
}