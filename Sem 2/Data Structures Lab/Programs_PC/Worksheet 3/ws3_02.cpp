#include <iostream>

using namespace std;

int findFirstOccurrence(int *, int, int);
int findLastOccurrence(int *, int, int);

int main()
{
    int i, n, target, len;
    cout << "Enter the number of elements in the sorted array: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter the elements of the sorted array:\n";
    for (i = 0; i < n; i++)
        cin >> arr[i];
    target = arr[n / 2];
    int first = findFirstOccurrence(arr, n, target);
    int last = findLastOccurrence(arr, n, target);

    if (first == -1 || last == -1)
    {
        cout << "Element not found in the array\n";
        return 0;
    }
    len = last - first + 1;
    if (len > n / 2)
        cout << "The element occurs more than half the size of the array\n";
    else
        cout << "The element does not occurs more than half the size of the array\n";
    return 0;
}

int findFirstOccurrence(int arr[], int len, int x)
{
    int low = 0, high = len - 1;
    int result = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (x == arr[mid])
        {
            result = mid;
            high = mid - 1;
        }
        else if (x < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return result;
}

int findLastOccurrence(int arr[], int len, int x)
{
    int low = 0, high = len - 1;
    int result = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (x == arr[mid])
        {
            result = mid;
            low = mid + 1;
        }
        else if (x < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return result;
}