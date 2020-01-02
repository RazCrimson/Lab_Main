#include <iostream>
#include <bits/stdc++.h>            // for memset

using namespace std;

class Matrix
{
    int **arr, rows, cols;

public:
    Matrix();
    int Sum();
    int lowerSum();
    int upperSum();
    int sumMajor();
    int sumMinor();
    int *rowSum();
    int *rowMin();
    int *rowMax();
    int *columnSum();
    int *columnMin();
    int *columnMax();
    int **transpose();
    bool isSymmetric();
    int countDuplicates();
    void changeDiagonals();
    void replaceDuplicates();
    void frequency();
    void displayUnique();
};

Matrix::Matrix()
{
    int x, y, temp;
    cout << "Enter the no. of rows and cols : ";
    cin >> x >> y;
    if (x < 1 || y < 1)
    {
        cout << "Error in array size!!";
        exit(0);
    }
    rows = x;
    cols = y;
    arr = new int *[rows];
    for (int i = 0; i < cols; i++)
        arr[i] = new int[cols]();

    cout << "Enter the elements of the matrix : ";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
        {
            cin >> temp;
            arr[i][j] = temp;
        }
}

int Matrix::Sum()
{
    int sum = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            sum += arr[i][j];
    return sum;
}

int Matrix::lowerSum()
{
    int sum = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j <= ((i < cols - 1) ? i : cols - 1); j++)
            sum += arr[i][j];
    return sum;
}

int Matrix::upperSum()
{
    int sum = 0;
    for (int i = 0; i < rows; i++)
        for (int j = i; j < cols; j++)
            sum += arr[i][j];
    return sum;
}

int Matrix::sumMajor()
{
    int sum = 0;
    for (int i = 0; i < ((rows < cols) ? rows : cols); i++)
        sum += arr[i][i];
    return sum;
}

int Matrix::sumMinor()
{
    int sum = 0;
    for (int i = rows; i >= 0; i--)
        sum += arr[i][i];
    return sum;
}

int *Matrix::rowSum()
{
    int *sum = new int[rows]();
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            sum[i] += arr[i][j];
    return sum;
}

int *Matrix::rowMin()
{
    int *min = new int[rows]();
    for (int i = 0; i < rows; i++)
        min[i] = 2147483647;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (min[i] > arr[i][j])
                min[i] = arr[i][j];
    return min;
}

int *Matrix::rowMax()
{
    int *maximum = new int[rows]();
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (maximum[i] < arr[i][j])
                maximum[i] = arr[i][j];
    return maximum;
}

int *Matrix::columnSum()
{
    int *sum = new int[cols]();
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            sum[j] += arr[i][j];
    return sum;
}

int *Matrix::columnMin()
{
    int *min = new int[cols]();
    for (int i = 0; i < cols; i++)
        min[i] = 2147483647;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (min[j] > arr[i][j])
                min[j] = arr[i][j];
    return min;
}

int *Matrix::columnMax()
{
    int *maximum = new int[cols]();
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (maximum[j] < arr[i][j])
                maximum[j] = arr[i][j];
    return maximum;
}

void Matrix::frequency()
{
    int i, j, k, counter = 0, num;
    int x, y, visited[rows][cols];
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            counter = 1;
            num = arr[i][j];
            if (visited[i][j] != 1)
            {
                for (x = 0; x < rows; x++)
                {
                    for (y = 0; y < cols; y++)
                    {
                        if ((i == x) && (j == y))
                            continue;

                        if (arr[i][j] == arr[x][y])
                        {
                            visited[x][y] = 1;
                            counter++;
                        }
                    }
                }
                printf("\nthe frequency of element %d  is %d", num, counter);
            }
        }
    }
}

void Matrix::replaceDuplicates()
{
    bool isDuplicate[rows][cols];
    memset(isDuplicate, 0, sizeof(isDuplicate));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {

            for (int x = 0; x < rows; i++)
            {
                for (int y = 0; y < cols; y++)
                {
                    if (i == x && j == y)
                        continue;
                    else if (arr[i][j] == arr[x][y])
                    {
                        isDuplicate[i][j] = true;
                        isDuplicate[x][y] = true;
                    }
                }
            }
        }
    }

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (!isDuplicate[i][j])
                arr[i][j] = -1;
}

int Matrix::countDuplicates()
{
    replaceDuplicates();
    int count = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (arr[i][j] == -1)
                count++;
    return count;
}

void Matrix::displayUnique()
{
    replaceDuplicates();
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] == -1)
                cout << "*";
            else
                cout << arr[i][j];
            cout << "\t";
        }
        cout << endl;
    }
}

int **Matrix::transpose()
{
    int **trans = new int *[cols]();
    for (int i = 0; i < cols; i++)
        trans[i] = new int[rows];
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            trans[i][j] = arr[j][i];
        }
    }
    return trans;
}

bool Matrix::isSymmetric()
{
    bool symm = 1;
    for (int i = 0; i < rows && symm; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] != arr[j][i])
            {
                symm = 0;
                break;
            }
        }
    }
    return symm;
}

void swap(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

void Matrix::changeDiagonals()
{
    int lim = (rows < cols) ? rows : cols;
    for (int i = 0; i < lim; i++)
        swap(arr[i][i], arr[i][lim - i]);
}


int main()
{
    Matrix a;
    // call methods as required
}