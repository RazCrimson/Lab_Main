#include <iostream>
#include <bits/stdc++.h>

using namespace std;

unsigned int Log5n(unsigned int n)
{
    return (n >= 5) ? 1 + Log5n(n / 5) : 0; 
}

int minimumNumber(int present, int sum, int value)
{
    if (sum >= value)
        return present - 1;
    else
    {
        sum += Log5n(present);
        return minimumNumber(present + 1, sum, value);
    }
}

int main()
{
    int val;
    cout << "Please enter the value: ";
    cin >> val;
    int ans = minimumNumber(1, 0, val);
    cout << "The answer is " << ans << endl;
}