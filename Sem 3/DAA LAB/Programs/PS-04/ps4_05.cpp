#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

void merge(int arr[], int start, int mid, int end) 
{ 
    int start2 = mid + 1; 
  
    if (arr[mid] <= arr[start2]) { 
        return; 
    } 
  
    while (start <= mid && start2 <= end) { 
  
        if (arr[start] <= arr[start2]) { 
            start++; 
        } 
        else { 
            int value = arr[start2]; 
            int index = start2; 
  
            while (index != start) { 
                arr[index] = arr[index - 1]; 
                index--; 
            } 
            arr[start] = value; 
  
            start++; 
            mid++; 
            start2++; 
        } 
    } 
} 
  
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) { 
  
        int m = l + (r - l) / 2; 
  
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
  
        merge(arr, l, m, r); 
    } 
} 

int findMinWidth(int colors[], int start, int minWidth, int size)
{
    int width = colors[start + 2] - colors[start];
    if (start + 2 == size)
        return minWidth;
    if (width == 2)
        return 2;
    if (width < minWidth)
        minWidth = width;
    return findMinWidth(colors, start + 1, minWidth, size);
}

int main()
{
    int test_cases;
    cout << "Please enter the number of Test cases: " << endl;
    cin >> test_cases;
    while (test_cases--)
    {
        int n, index = 0;
        cin >> n;
        int *arr = new int[n];
        cout << "Please enter the values of colors ending with -1" << endl;
        int val = 0;
        while (true)
        {
            cin >> val;
            if (val == -1)
                break;
            arr[index] = val;
            index++;
        }
        int cost;
        cout << "Please enter the cost of the ribbon" << endl;
        cin >> cost;
        mergeSort(arr, 0, n);
        int minWidth = findMinWidth(arr, 0, INT_MAX, n);
        int minimumCost = 2 * cost * minWidth * (arr[n - 1] - arr[0]);
        cout << minimumCost << endl;
    }
}