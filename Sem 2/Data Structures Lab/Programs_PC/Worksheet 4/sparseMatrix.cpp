#include "sparseMatrix.h"

sparseMatrix::sparseMatrix(int r, int c, int count)
{
    rows = r;
    cols = c;
    nonZero = count;
    matrix = new int *[nonZero + 1];
    for (int i = 0; i <= nonZero; i++)
        matrix[i] = new int[3]();

    matrix[0][0] = rows;
    matrix[0][1] = cols;
    matrix[0][2] = nonZero;
}

sparseMatrix::sparseMatrix(int **arr, int r, int c)
{
    rows = r;
    cols = c;
    nonZero = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            if (arr[i][j] != 0)
                nonZero++;
    }

    matrix = new int *[nonZero + 1];
    for (int i = 0; i <= nonZero; i++)
        matrix[i] = new int[3]();

    matrix[0][0] = rows;
    matrix[0][1] = cols;
    matrix[0][2] = nonZero;

    int index = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            if (arr[i][j] != 0)
            {
                matrix[index][0] = i;
                matrix[index][1] = j;
                matrix[index][2] = arr[i][j];
                index++;
            }
    }
}

void sparseMatrix::insert(int r, int c, int val)
{

    if (r > rows || c > cols)
        cout << "Wrong entry";

    else
    {
        nonZero++;
        matrix[0][2]++;
        matrix = (int **)realloc(matrix, sizeof(int *) * (nonZero + 1));
        matrix[nonZero] = new int[3]();

        matrix[nonZero][0] = r;
        matrix[nonZero][1] = c;
        matrix[nonZero][2] = val;
    }
}

sparseMatrix sparseMatrix::add(sparseMatrix b)
{

    if (rows != b.rows || cols != b.cols)
    {
        cout << "Matrices can't be added";
        return *this;
    }
    else
    {
        int apos = 1, bpos = 1;
        sparseMatrix result(rows, cols);

        while (apos < nonZero + 1 && bpos < b.nonZero + 1)
        {

            if (matrix[apos][0] > b.matrix[bpos][0] || (matrix[apos][0] == b.matrix[bpos][0] && matrix[apos][1] > b.matrix[bpos][1]))
            {
                result.insert(b.matrix[bpos][0], b.matrix[bpos][1], b.matrix[bpos][2]);
                bpos++;
            }
            else if (matrix[apos][0] < b.matrix[bpos][0] || (matrix[apos][0] == b.matrix[bpos][0] && matrix[apos][1] < b.matrix[bpos][1]))
            {
                result.insert(matrix[apos][0], matrix[apos][1], matrix[apos][2]);
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

        while (apos < nonZero + 1)
            result.insert(matrix[apos][0], matrix[apos][1], matrix[apos++][2]);

        while (bpos < b.nonZero + 1)
            result.insert(b.matrix[bpos][0], b.matrix[bpos][1], b.matrix[bpos++][2]);

        return result;
    }
}

sparseMatrix sparseMatrix::transpose()
{

    sparseMatrix result(cols, rows, nonZero);

    int *count = new int[cols + 1];

    for (int i = 0; i <= cols; i++)
        count[i] = 0;

    for (int i = 1; i <= nonZero; i++)
        count[matrix[i][1]]++;

    int *index = new int[cols + 1];
    index[0] = 0;

    for (int i = 1; i <= cols; i++)
        index[i] = index[i - 1] + count[i - 1];

    for (int i = 1; i <= nonZero; i++)
    {
        int rpos = ++index[matrix[i][1]];

        result.matrix[rpos][0] = matrix[i][1];
        result.matrix[rpos][1] = matrix[i][0];
        result.matrix[rpos][2] = matrix[i][2];
    }

    return result;
}

sparseMatrix sparseMatrix::multiply(sparseMatrix b)
{

    if (cols != b.rows)
    {
        cout << "Can't multiply, Invalid dimensions";
        return *this;
    }

    int apos, bpos;
    sparseMatrix result(rows, b.rows);

    apos = 1;
    while (apos <= nonZero)
    {
        int r = matrix[apos][0];
        bpos = 1;
        while (bpos <= b.nonZero)
        {
            int c = b.matrix[bpos][1];
            int tempa = apos;
            int tempb = bpos;
            int sum = 0;

            while (tempa <= nonZero && tempb <= b.nonZero && matrix[tempa][0] == r && b.matrix[tempb][1] == c)
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

            while (bpos <= b.nonZero && b.matrix[bpos][1] == c)
                bpos++;
        }

        while (apos <= nonZero && matrix[apos][0] == r)
            apos++;
    }

    return result;
}

bool sparseMatrix::isTwins(sparseMatrix b)
{
    if (rows == b.rows && cols != b.cols && nonZero != b.nonZero)
        return false;
    for (int i = 1; i <= nonZero; i++)
    {
        if (matrix[i][0] != b.matrix[i][0] || matrix[i][1] != b.matrix[i][1])
            return false;
    }
    return true;
}

void sparseMatrix::twinAdd(sparseMatrix b)
{
    if (!isTwins(b))
        cout << "The Matrices are not Twins";
    else
    {
        sparseMatrix result(rows, cols, nonZero);
        cout << "\nThe A Sum is : \n";
        this->print();
        cout << "\nThe B Sum is : \n";
        b.print();
        for (int i = 1; i <= nonZero; i++)
        {
            int val = 0;
            if (matrix[i][2] < b.matrix[i][2])
                val = -2;
            else if (matrix[i][2] > b.matrix[i][2])
                val = 2;
            else
                val = 1;

            result.matrix[i][0] = matrix[i][0];
            result.matrix[i][1] = matrix[i][1];
            result.matrix[i][2] = val;
        }
        cout << "\nThe Twins Sum is : \n";
        result.print();
    }
}

void sparseMatrix::print()
{
    cout << "\nRow\tColumn\tValue\n";
    for (int i = 0; i <= nonZero; i++)
        cout << matrix[i][0] << "\t  " << matrix[i][1] << "\t  " << matrix[i][2] << "\n";
}
