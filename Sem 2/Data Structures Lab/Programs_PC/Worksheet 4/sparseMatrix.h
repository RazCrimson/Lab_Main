#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;
class sparseMatrix
{
    int **matrix;
    int rows, cols, nonZero;

public:
    void print();
    void insert(int, int, int);
    void twinAdd(sparseMatrix);
    sparseMatrix(int, int, int = 0);
    sparseMatrix(int **, int, int);
    bool isTwins(sparseMatrix);
    sparseMatrix transpose();
    sparseMatrix add(sparseMatrix);
    sparseMatrix multiply(sparseMatrix);
};

