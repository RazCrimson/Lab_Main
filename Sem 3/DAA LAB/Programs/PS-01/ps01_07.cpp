#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void inorder(int arr[], vector<int> &vec, int n, int index)
{
    if (index >= n)
        return;
    inorder(arr, vec, n, 2 * index + 1);
    vec.push_back(arr[index]);
    inorder(arr, vec, n, 2 * index + 2);
}

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
    int n;
    cout << "Enter the number of elements : " << endl;
    cin >> n;
    int *arr = new int[n];
    cout << "Enter the elements in the In Order representation : " << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[1];
    vector<int> v;
    inorder(arr, v, n, 0);
    cout << minSwaps(v) << endl;
}