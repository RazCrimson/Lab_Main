#include <iostream>

class Sparse
{
    int **matrix;
    int rows, cols, nonZero;

public:
    Sparse(int, int);
    void print();
    void add(Sparse);
    void multiply(Sparse);
    void insert(int, int, int);
    Sparse transpose();
};

Sparse::Sparse(int r, int c)
{
    rows = r;
    cols = c;
    nonZero = 0;
    //for(int i=0;i<rows,i++)
    //{
    //   for(int j=0;j<cols;j++)
    //      if(arr[i][j] != 0)
    //         len++;
    //}
    matrix = new int *[100];
    for (int i = 0; i < 100; i++)
        matrix[i] = new int[3]();
}

void Sparse::insert(int r, int c, int val)
{

    if (r > rows || c > cols)
        std::cout << "Wrong entry";

    else
    {
        matrix[nonZero][0] = r;
        matrix[nonZero][1] = c;
        matrix[nonZero][2] = val;
        nonZero++;
    }
}

void Sparse::add(Sparse b)
{

    if (rows != b.rows || cols != b.cols)
        std::cout << "Matrices can't be added";

    else
    {
        int apos = 0, bpos = 0;
        Sparse result(rows, cols);

        while (apos < nonZero && bpos < b.nonZero)
        {

            if (matrix[apos][0] > b.matrix[bpos][0] || (matrix[apos][0] == b.matrix[bpos][0] && matrix[apos][1] > b.matrix[bpos][1]))
            {
                result.insert(b.matrix[bpos][0], b.matrix[bpos][1], b.matrix[bpos][2]);
                bpos++;
            }
            else if (matrix[apos][0] < b.matrix[bpos][0] || (matrix[apos][0] == b.matrix[bpos][0] && matrix[apos][1] < b.matrix[bpos][1]))
            {
                result.insert(matrix[apos][0], matrix[apos][1],matrix[apos][2]);
                apos++;
            }
            else
            {

                int addedval = matrix[apos][2] + b.matrix[bpos][2];

                if (addedval != 0)
                    result.insert(matrix[apos][0], matrix[apos][1], addedval);
                apos++;
                bpos++;
            }
        }

        while (apos < nonZero)
            result.insert(matrix[apos][0], matrix[apos][1], matrix[apos++][2]);

        while (bpos < b.nonZero)
            result.insert(b.matrix[bpos][0], b.matrix[bpos][1], b.matrix[bpos++][2]);

        result.print();
    }
}

Sparse Sparse::transpose()
{

    Sparse result(cols, rows);
    result.nonZero = nonZero;

    int *count = new int[cols + 1];

    for (int i = 0; i <= cols; i++)
        count[i] = 0;

    for (int i = 0; i < nonZero; i++)
        count[matrix[i][1]]++;

    int *index = new int[cols + 1];
    index[1] = 0;

    for (int i = 2; i <= cols; i++)
        index[i] = index[i - 1] + count[i - 1];

    for (int i = 0; i < nonZero; i++)
    {
        int rpos = index[matrix[i][1]]++;

        result.matrix[rpos][0] = matrix[i][1];
        result.matrix[rpos][1] = matrix[i][0];
        result.matrix[rpos][2] = matrix[i][2];
    }

    return result;
}

void Sparse::multiply(Sparse b)
{

    if (cols != b.rows)
    {
        std::cout << "Can't multiply, Invalid dimensions";
        return;
    }

    int apos, bpos;
    Sparse result(rows, b.rows);

    for (apos = 0; apos < nonZero;)
    {
        int r = matrix[apos][0];

        for (bpos = 0; bpos < b.nonZero;)
        {
            int c = b.matrix[bpos][1];
            int tempa = apos;
            int tempb = bpos;
            int sum = 0;

            while (tempa < nonZero && tempb < b.nonZero && matrix[tempa][0] == r && b.matrix[tempb][1] == c)
            {
                if (matrix[tempa][1] < b.matrix[tempb][0])
                    tempa++;
                else if (matrix[tempa][1] > b.matrix[tempb][0])
                    tempb++;
                else
                {
                    sum += matrix[tempa][2] * b.matrix[tempb][2];
                    tempa++;
                    tempb++;
                }
            }

            if (sum != 0)
                result.insert(r, c, sum);

            while (bpos < b.nonZero && b.matrix[bpos][1] == c)
                bpos++;
        }

        while (apos < nonZero && matrix[apos][0] == r)
            apos++;
    }

    result.print();
}

void Sparse::print()
{
    std::cout << "Dimension of the Matrix: " << rows << "x" << cols;
    std::cout << "\n Matrix: \nRow\tColumn\t Value\n";

    for (int i = 0; i < nonZero; i++)
        std::cout << matrix[i][0] << "\t  " << matrix[i][1] << "\t  " << matrix[i][2]<<"\n";
}

int main()
{

    Sparse a(4, 4);
    Sparse b(4, 4);

    a.insert(1, 2, 10);
    a.insert(1, 4, 12);
    a.insert(3, 3, 5);
    a.insert(4, 1, 15);
    a.insert(4, 2, 12);
    b.insert(1, 3, 8);
    b.insert(2, 4, 23);
    b.insert(3, 3, 9);
    b.insert(4, 1, 20);
    b.insert(4, 2, 25);

    std::cout << "Addition: ";
    a.add(b);
    std::cout << "\nMultiplication: ";
    a.multiply(b);
    std::cout << "\nTranspose: ";
    Sparse atranspose = a.transpose();
    atranspose.print();
}
