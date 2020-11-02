#include <iostream>
#include <list>

using namespace std;

//returns max of 2 binary numbers
list<bool> getBigger(list<bool> list_1, list<bool> list_2)
{
    list<bool>::iterator first = list_1.begin(), second = list_2.begin();
    while (first != list_1.end())
    {
        if (*first ^ *second == 0)
        {
            first++;
            second++;
        }
        else
            return *first ? list_1 : list_2;
    }
    return list_1;
}

int main()
{
    list<list<bool>> binaryNums;
    char check;
    int count = 0;
    int val;
    cout << "Please enter the Binary numbers " << endl;
    do
    {
        cout << "Please enter Binary Number (" << count + 1 << ") Press -1 to stop" << endl;
        list<bool> vec;
        while (true)
        {
            cin >> val;
            if (val == -1)
                break;
            vec.push_back(val);
        }
        binaryNums.push_back(vec);
        cout << "Do you want to add a new number ? " << endl
             << "Press y to enter a new number n to stop: ";
        cin >> check;
        count++;
    } while (check == 'y');

    list<bool> max = binaryNums.front();
    for (auto eachList : binaryNums)
        max = getBigger(max, eachList);

    cout << "\nMax Binary Digit : " << endl;
    for(auto digit: max)
        cout << digit;
    
    return 0;
}