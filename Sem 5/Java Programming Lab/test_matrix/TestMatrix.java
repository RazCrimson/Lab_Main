package test_matrix;

public class TestMatrix {

    public static void main(String[] args) {
        try {
            int rows = 3, cols = 3;
            int[][] array = {{6, 6, 6}, {6, 6, 6}, {6, 6, 6}};

            Matrix m1 = new Matrix(rows, cols);
            Matrix m2 = new Matrix(rows, cols);
            Matrix m3 = new Matrix(array);


            for (int i = 0; i < m1.getNumberOfRows(); i++) {
                for (int j = 0; j < m1.getNumberOfCols(); j++) {
                    m1.setElement(i, j, 1);
                    m2.setElement(i, j, 2);
                }
            }
            System.out.println("Matrix A:");
            m1.print();

            System.out.println("Matrix B:");
            m2.print();

            System.out.println("Matrix C:");
            m3.print();

            System.out.println("Matrix B + A:");
            m2.add(m1).print();

            System.out.println("Matrix B - A:");
            m2.subtract(m1).print();

            System.out.println("Matrix BA:");
            m2.multiply(m1).print();

            System.out.println("Matrix B Transpose:");
            m2.getTranspose().print();

            assert m2.multiply(m1).equals(m3);
            assert m2.equals(m2.getTranspose().getTranspose());

        } catch (Exception e) {
            System.err.println(e.getMessage());
        }

    }
}
