#include <iostream>
#include <bits/stdc++.h>

using namespace std;

unsigned int log5n(unsigned int n)
{
    return (n >= 5) ? 1 + log5n(n / 5) : 0;
}

unsigned int numberOfTimesDivisibleBy5(unsigned int n)
{
    return (n % 5 == 0) ? 1 + numberOfTimesDivisibleBy5(n / 5) : 0;
}

int minimumNumber(int present, int sum, int value)
{
    if (sum >= value)
        return present - 1;
    else
    {
        sum += numberOfTimesDivisibleBy5(present);
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