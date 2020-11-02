#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    cout << "Please enter the number : ";
    int val, temp;
    cin >> val;

    temp = val - 2;

    // if number is even
    if ((val & 0x1) == 0)
        temp -= 1;

    // iterating till we get the gcd is 1
    while (__gcd(val, temp) != 1 && temp > 1)
        temp -= 2;

    if (temp < 1)
        cout << "We dont have a valid Co-prime" << endl;
    else
        cout << "The value of the number which is a coprime of the given number and is less than given value - 1 is " << temp << endl;
    return 0;
}