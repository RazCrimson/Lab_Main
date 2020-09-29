#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minSwaps(vector<int> &vec)
{
    vector<pair<int, int>> arrAndPos(vec.size());
    int swapCount = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        arrAndPos[i].first = vec[i];
        arrAndPos[i].second = i;
    }
    sort(arrAndPos.begin(), arrAndPos.end());
    for (int i = 0; i < arrAndPos.size(); i++)
    {
        if (i == arrAndPos[i].second)
            continue;
        else
        {
            swap(arrAndPos[i].first, arrAndPos[arrAndPos[i].second].first);
            swap(arrAndPos[i].second, arrAndPos[arrAndPos[i].second].second);
        }

        if (i != arrAndPos[i].second)
            --i;
        swapCount++;
    }
    return swapCount;
}

int main()
{
    int n, temp;
    vector<int> v;
    cout << "Enter the number of elements : " << endl;
    cin >> n;
    cout << "Enter the elements of BST in the In Order representation : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        v[i] = temp;
    }
    cout << minSwaps(v) << endl;
}