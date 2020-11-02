#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    string sortOrder, input;
    cin >> sortOrder >> input;

    sort(input.begin(), input.end(), [sortOrder](char a, char b) {
        return sortOrder.find(a) < sortOrder.find(b);
    });

    cout << "Sorted String : " << input << endl;
    return 0;
}