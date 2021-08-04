package test_matrix;


import java.util.Arrays;

public class Matrix {
    private final int rows, cols;
    private final int[][] elements;

    Matrix(int rows, int cols) {
        if (rows < 1 || cols < 1) {
            throw new IndexOutOfBoundsException("A Matrix requires minimum of 1 row and 1 column");
        }
        this.rows = rows;
        this.cols = cols;
        this.elements = new int[rows][cols];
    }

    Matrix(int[][] elements) {
        if (elements.length < 1)
            throw new IndexOutOfBoundsException("Matrix requires a minimum of 1 row");
        if (elements[0].length < 1)
            throw new IndexOutOfBoundsException("Matrix requires a minimum of 1 column");

        this.rows = elements.length;
        this.cols = elements[0].length;

        for (int i = 1; i < rows; i++)
            if (elements[i].length != this.cols)
                throw new IndexOutOfBoundsException("Matrix requires columns of even sizes");

        this.elements = elements;
    }

    public int getNumberOfRows() {
        return this.rows;
    }

    public int getNumberOfCols() {
        return this.cols;
    }

    private boolean isValidIndex(int row, int col) {
        return 0 <= row && row < rows && 0 <= col && col < cols;
    }

    private boolean hasEqualDimensions(Matrix m) {
        return rows == m.rows && cols == m.cols;
    }

    private boolean isCompatible(Matrix m) {
        return cols == m.getNumberOfRows();
    }

    public int getElement(int row, int col) throws IndexOutOfBoundsException {
        if (isValidIndex(row, col))
            return this.elements[row][col];
        throw new IndexOutOfBoundsException("Invalid index for the Matrix");
    }

    public boolean setElement(int row, int col, int element) {
        if (isValidIndex(row, col)) {
            this.elements[row][col] = element;
            return true;
        }
        return false;
    }

    public void print() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                System.out.print(elements[i][j] + " ");
            System.out.println();
        }
    }

    public Matrix add(Matrix m) throws Exception {
        if (!hasEqualDimensions(m))
            throw new Exception("Matrix sizes differ!");

        Matrix result = new Matrix(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.elements[i][j] = elements[i][j] + m.elements[i][j];

        return result;
    }

    public Matrix subtract(Matrix m) throws Exception {
        if (!hasEqualDimensions(m))
            throw new Exception("Matrix sizes differ!");

        Matrix result = new Matrix(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.elements[i][j] = elements[i][j] - m.elements[i][j];

        return result;
    }

    public Matrix multiply(Matrix m) throws Exception {
        if (!isCompatible(m))
            throw new Exception("Matrix are not compatible!");

        Matrix result = new Matrix(rows, m.cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < m.cols; j++)
                for (int k = 0; k < m.rows; k++)
                    result.elements[i][j] += elements[i][k] * m.elements[k][j];

        return result;
    }

    public Matrix getTranspose() {
        Matrix result = new Matrix(cols, rows);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.elements[j][i] = elements[i][j];

        return result;
    }

    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        else if (obj == null || obj.getClass() != this.getClass())
            return false;

        Matrix m = (Matrix) obj;
        if (!hasEqualDimensions(m))
            return false;

        return Arrays.deepEquals(elements, m.elements);
    }

}
