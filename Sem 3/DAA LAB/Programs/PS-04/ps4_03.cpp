#include <iostream>
#include <vector>
using namespace std;

int wrapper(vector<int> &, int);
int findSpl(vector<int> &, int, int, int, int);

int wrapper(vector<int> &v, int k)
{
    int count = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (findSpl(v, k, i, 0, i - 1) || findSpl(v, k, i, i + 1, v.size() - 1))
            count += v[i];
    }
    return count;
}

int findSpl(vector<int> &v, int k, int index, int start, int end)
{
    if (end - start + 1 < k)
    {
        return 0;
    }
    if (end - start + 1 == k)
    {
        bool flag = true;
        for (int i = start; i <= end; i++)
        {
            if (v[i] < v[index])
                flag = false;
        }
        if (flag)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return findSpl(v, k, index, start, end - 1) || findSpl(v, k, index, start + 1, end);
}

int main()
{
    int length, number, k;
    vector<int> vec;
    cout << "Enter the number of elements: ";
    cin >> length;
    cout << "Enter the elements\n";
    for (int i = 0; i < length; i++)
    {
        cin >> number;
        vec.push_back(number);
    }
    cout << "Enter the number: ";
    cin >> k;
    cout << "The speciality of the sequence is" << wrapper(vec, k) << endl;
}