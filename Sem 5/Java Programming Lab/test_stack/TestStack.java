package test_stack;

public class TestStack {

    public static void main(String[] args) {

        Stack stack = new Stack(10);
        for (int i = 0; i < 10; i++)
            stack.push(i);

        try {
            stack.push(10);
        } catch (IndexOutOfBoundsException e) {
            assert "StackException::Overflow".equals(e.getMessage());
        }

        for (int i = 9; i > -1; i--)
            assert i == stack.pop();

        try {
            stack.pop();
        } catch (IndexOutOfBoundsException e) {
            assert "StackException::Underflow".equals(e.getMessage());
        }

        System.out.println("Basic Tests Completed!");
    }
}
