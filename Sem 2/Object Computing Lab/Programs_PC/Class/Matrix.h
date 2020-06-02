#include <iostream>

using namespace std;


class Matrix
{

    int rows, cols;
    int **matrix;

public:
    Matrix(int, int);
    Matrix(Matrix &);
    ~Matrix();
    void read();
    void display();
    Matrix operator*(Matrix &);
    Matrix operator +(Matrix &);
    Matrix transpose();
};

Matrix::Matrix(int r, int c)
{
    rows = r;
    cols = c;
    matrix = new int *[rows]();
    for (int i = 0; i < rows; i++)
        matrix[i] = new int[cols]();
}

Matrix::Matrix(Matrix &a)
{
    rows = a.rows;
    cols = a.cols;
    matrix = new int *[rows]();
    for (int i = 0; i < rows; i++)
        matrix[i] = new int[cols]();

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = a.matrix[i][j];

}

Matrix::~Matrix()
{
    for (int i = 0; i < rows; i++)
        delete[] matrix[i];
    delete[] matrix;
    }

void Matrix::read()
{
    cout << "Enter the elements of the matrix : ";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> matrix[i][j];
}

void Matrix::display()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }
}

Matrix Matrix::operator +(Matrix &b)
{
    Matrix result(*this);
    if (rows != b.rows || cols != b.cols)
        cout << "The Matrices to be added are not of the same order.\n";
    else
    {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.matrix[i][j] += b.matrix[i][j];
    }
    return result;
}

Matrix Matrix::transpose()
{
    Matrix result(cols, rows);
    for (int i = 0; i < result.rows; i++)
        for (int j = 0; j < result.cols; j++)
            result.matrix[i][j] += matrix[j][i];
    return result;

}

Matrix Matrix::multiply(Matrix &b)
{
    Matrix result(rows, b.cols);
    if (cols != b.rows)
        cout << "The Matrices cant be multiplied.\n";
    else
    {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < b.cols; j++)
                for (int k = 0; k < b.rows; k++)
                    result.matrix[i][j] += matrix[i][k] * b.matrix[k][j];
    }
    return result;
}
