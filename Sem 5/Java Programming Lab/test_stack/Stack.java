package test_stack;

public class Stack {
    private final int size;
    private final int[] elements;
    private int top;

    public Stack(int size) {
        this.top = -1;
        this.size = size;
        this.elements = new int[this.size];
    }

    public boolean isFull() {
        return this.top + 1 >= this.size;
    }

    public boolean isEmpty() {
        return this.top == -1;
    }

    public void push(int element) throws IndexOutOfBoundsException {
        if (isFull())
            throw new IndexOutOfBoundsException("StackException::Overflow");
        this.top += 1;
        this.elements[this.top] = element;
    }

    public int pop() throws IndexOutOfBoundsException {
        if (isEmpty())
            throw new IndexOutOfBoundsException("StackException::Underflow");
        this.top -= 1;
        return this.elements[this.top + 1];
    }

    public int getSize() {
        return this.size;
    }

    public int getTop() throws IndexOutOfBoundsException {
        if (isEmpty())
            throw new IndexOutOfBoundsException("StackException::Underflow");
        return this.elements[this.top];
    }
}
