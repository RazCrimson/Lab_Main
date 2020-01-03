#include <string>
#include <iostream>
#include "sparseMatrix.h"

using namespace std;

int main()
{
    int r, c;
    cout << "\nEnter the no. of rows and columns of A : ";
    cin >> r >> c;
    if (r < 1 || c < 1)
    {
        cout << "Error in size!!";
        exit(0);
    }
    int **arr = new int *[r];
    for (int i = 0; i < r; i++)
        arr[i] = new int[c];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << "\nEnter the elements at["<<i<<"]["<<j<<"] : ";
            cin >> arr[i][j];
        }
    }
    sparseMatrix a(arr, r, c);
    cout << "Triple Represenetation of A :\n";
    a.print();
    cout << "Transpose of A :\n";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cout << arr[j][i] << "\t";
        cout << endl;
    }
    cout << "Transpose of Triple Represenetation of A : ";
    a.transpose().print();
    return 0;
}
