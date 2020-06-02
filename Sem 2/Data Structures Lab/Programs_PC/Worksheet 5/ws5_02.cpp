#include <iostream>
#include <cstdio>
#include "Stack.hpp"

using namespace std;

int main()
{
    Stack<char> s1;
    s1.assignSize(20);
    char input;
    cin >> input;
    while (input != '+')
    {
        if (input == '#')
            s1.pop();
        else
        {
            s1.push(input);
        }
        cin >> input;
    }
    s1.displayFromBottom();
    return 0;
}