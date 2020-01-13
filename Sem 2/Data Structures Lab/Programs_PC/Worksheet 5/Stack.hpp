#include <iostream>

using namespace std;

class Stack
{
    int *stack, top, size;

public:
    Stack();
    Stack(int[], int, int = 0);
    int push(int);
    int pop();
    int count();
    void assignSize(int);
    void displayFromTop();
    void displayFromBottom();
    ~Stack();
};

Stack::Stack()
{
    top = -1;
    stack = new int[0]();
    size = 0;
}

Stack::Stack(int arr[], int len, int max)
{
    if (max == 0)
        max = len;
    stack = new int[max]();
    size = max;
    top = -1;
    for (int i = 0; i < len; i++)
        push(arr[i]);
}

Stack::~Stack()
{
    delete[] stack;
}

void Stack::assignSize(int max)
{
    delete[] stack;
    stack = new int[size]();
    top = -1;
    size = max;
}

int Stack::push(int element)
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

int Stack::pop()
{
    if (top == -1)
    {
        throw __throw_out_of_range;
        return 0;
    }
    else
    {
        int element = stack[top];
        top -= 1;
        return element;
    }
}

void Stack::displayFromBottom()
{
    if (top == -1)
    {
        cout << "Empty Stack\n";
        return;
    }
    Stack temp;
    temp.assignSize(size);
    while (top != -1)
    {
        int element = pop();
        temp.push(element);
    }
    while (temp.top != -1)
    {
        int element = temp.pop();
        cout << "\n"
             << element;
        push(element);
    }
}

void Stack::displayFromTop()
{
    if (top == -1)
    {
        cout << "Empty Stack\n";
        return;
    }
    Stack temp;
    temp.assignSize(size);
    while (top != -1)
    {
        int element = pop();
        cout << "\n"
             << element;
        temp.push(element);
    }
    while (temp.top != -1)
    {
        int element = temp.pop();
        push(element);
    }
}

int Stack::count()
{
    return top + 1;
}