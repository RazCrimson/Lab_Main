package test_string_matrix;

public class TestStringMatrix {

    public static void main(String[] args) {
        try {
            int rows = 3, cols = 3;
            String[][] array = {{"1", "2", "3"}, {"4", "5", "6"}, {"7", "8", "9"}};

            StringMatrix m1 = new StringMatrix(rows, cols);
            StringMatrix m2 = new StringMatrix(rows, cols);
            StringMatrix m3 = new StringMatrix(array);


            for (int i = 0; i < m1.getNumberOfRows(); i++) {
                for (int j = 0; j < m1.getNumberOfCols(); j++) {
                    m1.setElement(i, j, "one");
                    m2.setElement(i, j, "two");
                }
            }
            System.out.println("Matrix A:");
            m1.print();

            System.out.println("Matrix B:");
            m2.print();

            System.out.println("Matrix C:");
            m3.print();

            System.out.println("Matrix A + C:");
            m2.add(m3).print();

            System.out.println("Matrix B + A:");
            m2.add(m1).print();

            System.out.println("Matrix C Transpose:");
            m3.getTranspose().print();

            assert m3.equals(m3.getTranspose().getTranspose());

        } catch (Exception e) {
            System.err.println(e.getMessage());
        }

    }
}
