#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMinWidth(vector<int> colors, int start, int minWidth)
{
    int width = colors[start + 2] - colors[start];
    if (start + 2 == colors.size())
        return minWidth;
    if (width == 2)
        return 2;
    if (width < minWidth)
        minWidth = width;
    return findMinWidth(colors, start + 1, minWidth);
}

int main()
{
    int test_cases;
    cout << "Please enter the number of Test cases: " << endl;
    cin >> test_cases;
    int count_testcases = 0;
    while (count_testcases < test_cases)
    {
        vector<int> colors;
        cout << "Please enter the values of colors ending with -1" << endl;
        int val = 0;
        while (true)
        {
            cin >> val;
            if (val == -1)
                break;
            colors.push_back(val);
        }
        int cost;
        cout << "Please enter the cost of the ribbon" << endl;
        cin >> cost;
        sort(colors.begin(), colors.end());
        int minWidth = findMinWidth(colors, 0, 0);
        int size = colors.size();
        int minimumCost = 2 * cost * (minWidth + (colors[size - 1] - colors[0]));
        cout << "The minimum cost for test case " << count_testcases + 1 << "is " << minimumCost << "." << endl;
        count_testcases++;
    }
}