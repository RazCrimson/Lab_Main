#include <iostream>

using namespace std;

template <typename T>
class Stack
{
    T *stack;
    int top, size;

public:
    Stack();
    Stack(T[], int, int = 0);
    int push(T);
    T pop();
    int count();
    void assignSize(int);
    void displayFromTop();
    void displayFromBottom();
    ~Stack();
};

template <typename T>
Stack<T>::Stack()
{
    top = -1;
    stack = new T[0]();
    size = 0;
}

template <typename T>
Stack<T>::Stack(T arr[], int len, int max)
{
    if (max == 0)
        max = len;
    stack = new T[max]();
    size = max;
    top = -1;
    for (int i = 0; i < len; i++)
        push(arr[i]);
}

template <typename T>
Stack<T>::~Stack()
{
    delete[] stack;
}

template <typename T>
void Stack<T>::assignSize(int max)
{
    delete[] stack;
    stack = new T[size]();
    top = -1;
    size = max;
}

template <typename T>
int Stack<T>::push(T element)
{
    if (top + 1 == size)
    {
        throw __throw_out_of_range;
        return 0;
    }
    else
    {
        top += 1;
        stack[top] = element;
        return 0;
    }
}

template <typename T>
T Stack<T>::pop()
{
    if (top == -1)
    {
        throw __throw_out_of_range;
        return 0;
    }
    else
    {
        T element = stack[top];
        top -= 1;
        return element;
    }
}

template <typename T>
void Stack<T>::displayFromBottom()
{
    if (top == -1)
    {
        cout << "Empty Stack\n";
        return;
    }
    Stack<T> temp;
    temp.assignSize(size);
    while (top != -1)
    {
        T element = pop();
        temp.push(element);
    }
    while (temp.top != -1)
    {
        T element = temp.pop();
        cout << "\n"
             << element;
        push(element);
    }
}

template <typename T>
void Stack<T>::displayFromTop()
{
    if (top == -1)
    {
        cout << "Empty Stack\n";
        return;
    }
    Stack<T> temp;
    temp.assignSize(size);
    while (top != -1)
    {
        T element = pop();
        cout << "\n"
             << element;
        temp.push(element);
    }
    while (temp.top != -1)
    {
        T element = temp.pop();
        push(element);
    }
}

template <typename T>
int Stack<T>::count()
{
    return top + 1;
}