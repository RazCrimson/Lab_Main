#include <bits/stdc++.h>
using namespace std;

int merge(int arr[], int leftIndex, int mid, int end)
{
    int rightIndex = mid + 1;
    int counter = 0;

    if (arr[mid] <= arr[rightIndex])
        return 0;

    while (leftIndex <= mid && rightIndex <= end)
    {
        if (arr[leftIndex] <= arr[rightIndex])
        {
            leftIndex++;

        }
        else
        {
            int value = arr[rightIndex];
            int index = rightIndex;

            counter += mid - leftIndex + 1;

            while (index != leftIndex)
            {
                arr[index] = arr[index - 1];
                index--;
            }
            arr[leftIndex] = value;

            mid++;
            leftIndex++;
            rightIndex++;
        }
    }
    return counter;
}

int mergeSort(int arr[], int l, int r)
{
    int count = 0;
    if (l < r)
    {
        int m = l + (r - l) / 2;

        count += mergeSort(arr, l, m);
        count += mergeSort(arr, m + 1, r);

        count += merge(arr, l, m, r);
    }
    return count;
}

void print(int A[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    int n;
    cout << "Enter the number of Elements : ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter the Elements : ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    cout << "\nNumber of Inversions : " << mergeSort(arr, 0, n - 1) << endl;
    print(arr, n);
    return 0;
}