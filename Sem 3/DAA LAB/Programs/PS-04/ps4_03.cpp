#include <iostream>
#include <vector>

using namespace std;

int findSpecial(vector<int> sequence, int start, int end, int k, int index)
{
    if (end - start + 1 < k)
        return 0;
    if (end - start + 1 == k)
    {
        bool flag = true;
        for (unsigned i = start; i <= end; i++)
        {
            if (sequence[i] < sequence[index])
            {
                flag = false;
                break;
            }
        }
        if (flag)
            return sequence[index];
        else
            return 0;
    }
    return findSpecial(sequence, start, end - 1, k, index) || findSpecial(sequence, start + 1, end, k, index);
}

int wrapper(vector<int> sequence, int k)
{
    int sum = 0;
    for (unsigned i = 0; i < sequence.size(); i++)
    {
        if (findSpecial(sequence, 0, i - 1, k, i) || findSpecial(sequence, i + 1, sequence.size() - 1, k, i))
            sum += sequence[i];
    }
    return sum;
}

int main()
{
    vector<int> sequence;
    int val;
    int k;
    cout << "Please enter the sequence and press -1 to stop" << endl;
    while (true)
    {
        cin >> val;
        if (val == -1)
            break;
        sequence.push_back(val);
    }
    cout << "Please enter the value of k: ";
    cin >> k;
    int ans = wrapper(sequence, k);
    cout << "The speciality of the sequence is " << ans << endl;
}