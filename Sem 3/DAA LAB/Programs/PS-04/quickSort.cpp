#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int Partition(vector<int> &v, int begin, int end)
{
    int &pivot = v[begin];
    int i = begin, j = end;
    while (i < j && i <= end && j >= begin)
    {
        while (v[i] <= pivot && i < end)
            i++;
        while (v[j] > pivot && j > begin)
            j--;
        if (i < j)
            swap(v[i], v[j]);
    }
    swap(pivot, v[j]);
    return j;
}

void QuickSort(vector<int> &v, int l, int r)
{
    if (l < r)
    {
        int s = Partition(v, l, r);
        QuickSort(v, l, s - 1);
        QuickSort(v, s + 1, r);
    }
}

int main()
{
    vector<int> nums;
    for (size_t i = 4; i > 0; i--)
        nums.push_back(i);

    QuickSort(nums, 0, nums.size() - 1);

    for (size_t i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;
    return 0;
}