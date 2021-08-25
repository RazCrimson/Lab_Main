package matrixoperations;

import mathdatatypes.ComplexNumber;

public class TestComplexMatrix {

    public static void main(String[] args) {
        try {
            int rows = 3, cols = 3;
            ComplexNumber[][] array = {
                    {new ComplexNumber(6,6), new ComplexNumber(6,6), new ComplexNumber(6,6)},
                    {new ComplexNumber(6,6), new ComplexNumber(6,6), new ComplexNumber(6,6)},
                    {new ComplexNumber(6,6), new ComplexNumber(6,6), new ComplexNumber(6,6)}};

            ComplexMatrix m1 = new ComplexMatrix(rows, cols);
            ComplexMatrix m2 = new ComplexMatrix(rows, cols);
            ComplexMatrix m3 = new ComplexMatrix(array);


            for (int i = 0; i < m1.getNumberOfRows(); i++) {
                for (int j = 0; j < m1.getNumberOfCols(); j++) {
                    m1.setElement(i, j, new ComplexNumber(1,1));
                    m2.setElement(i, j, new ComplexNumber(2,2));
                }
            }
            System.out.println("Matrix A:");
            System.out.println(m1);

            System.out.println("Matrix B:");
            System.out.println(m2);

            System.out.println("Matrix C:");
            System.out.println(m3);

            System.out.println("Matrix B + A:");
            System.out.println(m2.add(m1));

            System.out.println("Matrix B - A:");
            System.out.println(m1.subtract(m2));

            System.out.println("Matrix BA:");
            System.out.println(m2.multiply(m1));

            System.out.println("Matrix B Transpose:");
            System.out.println(m2.getTranspose());

            assert m2.multiply(m1).equals(m3);
            assert m2.equals(m2.getTranspose().getTranspose());

        } catch (Exception e) {
            System.err.println(e.getMessage());
        }

    }
}
