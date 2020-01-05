#include <iostream>

using namespace std;

int main()
{
    int n, pairs = 0;
    cout << "\nEnter the no. of elements : ";
    cin >> n;
    if (n < 1)
    {
        cout << "Error in size!!";
        exit(0);
    }
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter the elements at[" << i << "] : ";
        cin >> arr[i];
    }
    cout << "Inversion Pairs : \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                cout << "(" << i << "," << j << ")\n";
                pairs++;
            }
        }
    }
    cout << "The no. of Inversin pairs is " << pairs << endl;
    return 0;
}