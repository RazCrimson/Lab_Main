package matrixoperations;

import mathdatatypes.ComplexNumber;

import java.util.Arrays;

public class ComplexMatrix {
    private final int rows, cols;
    private final ComplexNumber[][] elements;

    public ComplexMatrix(int rows, int cols) {
        if (rows < 1 || cols < 1) {
            throw new IndexOutOfBoundsException("A Matrix requires minimum of 1 row and 1 column");
        }
        this.rows = rows;
        this.cols = cols;
        this.elements = new ComplexNumber[rows][cols];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < rows; j++) {
                this.elements[i][j] = new ComplexNumber(0, 0);
            }
        }
    }

    public ComplexMatrix(ComplexNumber[][] elements) {
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

    private boolean hasInEqualDimensions(ComplexMatrix m) {
        return rows != m.rows || cols != m.cols;
    }

    private boolean isCompatible(ComplexMatrix m) {
        return cols == m.getNumberOfRows();
    }

    public ComplexNumber getElement(int row, int col) throws IndexOutOfBoundsException {
        if (isValidIndex(row, col))
            return this.elements[row][col];
        throw new IndexOutOfBoundsException("Invalid index for the Matrix");
    }

    public boolean setElement(int row, int col, ComplexNumber element) {
        if (isValidIndex(row, col)) {
            this.elements[row][col] = element;
            return true;
        }
        return false;
    }

    public String toString() {
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                res.append(elements[i][j]).append(" ");
            res.append('\n');
        }
        return res.toString();
    }

    public ComplexMatrix add(ComplexMatrix m) throws Exception {
        if (hasInEqualDimensions(m))
            throw new Exception("Matrix sizes differ!");

        ComplexMatrix result = new ComplexMatrix(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.elements[i][j].add(m.elements[i][j]);

        return result;
    }

    public ComplexMatrix subtract(ComplexMatrix m) throws Exception {
        if (hasInEqualDimensions(m))
            throw new Exception("Matrix sizes differ!");

        ComplexMatrix result = new ComplexMatrix(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.elements[i][j].subtract(m.elements[i][j]);

        return result;
    }

    public ComplexMatrix multiply(ComplexMatrix m) throws Exception {
        if (!isCompatible(m))
            throw new Exception("Matrix are not compatible!");

        ComplexMatrix result = new ComplexMatrix(rows, m.cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < m.cols; j++)
                for (int k = 0; k < m.rows; k++)
                    result.elements[i][j].add(ComplexNumber.multiply(elements[i][k], m.elements[k][j]));

        return result;
    }

    public ComplexMatrix getTranspose() {
        ComplexMatrix result = new ComplexMatrix(cols, rows);
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

        ComplexMatrix m = (ComplexMatrix) obj;
        if (hasInEqualDimensions(m))
            return false;

        return Arrays.deepEquals(elements, m.elements);
    }

}
