#include <iostream>
#include <cstdlib>

using namespace std;

void print1(int arr[][5], int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
            cout << arr[i][j] << "\t";
        cout << endl;
    }
}

void print2(int arr[][6], int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 6; j++)
            cout << arr[i][j] << "\t";
        cout << endl;
    }
}

int main()
{
    int arr[6][5], sum = 0, colMinMaxSum[3][5] = {{0}}, rowMinMaxSum[3][6] = {{0}};
    int minimum = 2147483647, maximum1, maximum2, sumMain, sumMinor, sumUpper, sumLower, temp;
    maximum1 = maximum2 = sumMain = sumMinor = sumUpper = sumLower = 0;
    cout << "Enter the Elements of the 6x5 Matrix : ";
    for (int i = 0; i < 6; i++)
        rowMinMaxSum[0][i] = 2147483647;
    for (int i = 0; i < 5; i++)
        colMinMaxSum[0][i] = 2147483647;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> temp;

            arr[i][j] = temp;
            if (minimum > temp)
                minimum = temp;
            if (maximum1 < temp)
                maximum1 = temp;
            else if (arr[i][j] > maximum2 && arr[i][j] < maximum1)
                maximum2 = arr[i][j];
            if (rowMinMaxSum[0][i] > temp)
                rowMinMaxSum[0][i] = temp;
            if (rowMinMaxSum[1][i] < temp)
                rowMinMaxSum[1][i] = temp;
            if (colMinMaxSum[0][j] > temp)
                colMinMaxSum[0][j] = temp;
            if (colMinMaxSum[1][j] < temp)
                colMinMaxSum[1][j] = temp;
            rowMinMaxSum[2][i] += temp;
            colMinMaxSum[2][j] += temp;
            sum += temp;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        sumMain += arr[i][i];
        sumMinor += arr[5 - i][5 - i];
    }
    for (int i = 1; i < 6; i++)
    {
        for (int j = 0; j < i; j++)
            sumLower += arr[i][j];
    }
    for (int i = 0; i < 6; i++)
    {
        for (int j = i + 1; j < 5; j++)
            sumUpper += arr[i][j];
    }
    cout << "lo,up" << sumLower << sumUpper;
    print1(arr, 6);
    print1(colMinMaxSum, 3);
    print2(rowMinMaxSum, 3);
    return 0;
}
