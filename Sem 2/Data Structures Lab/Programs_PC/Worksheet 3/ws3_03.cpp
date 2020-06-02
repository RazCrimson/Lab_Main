#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n = 0;
    cout << "Enter the no. of Elements : ";
    cin >> n;
    if (n < 1)
    {
        cout << "Error with the array size!!";
        exit(0);
    }
    int *arr = new int[n];
    int i = 0;
    for (int j = 0; j < n; j++)
    {
        if (arr[j] < 0)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    for (int i = 0; i < n; i++)
        cout<< arr[i]<<'\t';
    return 0;
}
