#include <iostream>

using namespace std;

class CarStack
{
    int *stack;
    int top, size;

public:
    CarStack();
    CarStack(int[], int, int = 0);
    int push(int);
    int pop();
    int pop(int);
    int count();
    void assignSize(int);
    void display();
    ~CarStack();
};

CarStack::CarStack()
{
    top = -1;
    stack = new int[0]();
    size = 0;
}

CarStack::CarStack(int arr[], int len, int max)
{
    if (max == 0)
        max = len;
    stack = new int[max]();
    size = max;
    top = -1;
    for (int i = 0; i < len; i++)
        push(arr[i]);
}

CarStack::~CarStack()
{
    delete[] stack;
}

void CarStack::assignSize(int max)
{
    delete[] stack;
    size = max;
    stack = new int[size]();
    top = -1;
}

int CarStack::push(int element)
{
    if (top + 1 == size)
    {
        return -1;
    }
    else
    {
        top += 1;
        stack[top] = element;
        return 0;
    }
}

int CarStack::pop()
{
    if (top == -1 || top >= size)
    {
        return -1;
    }
    else
    {
        int element = stack[top];
        top -= 1;
        return element;
    }
}

void CarStack::display()
{
    if (top == -1)
    {
        cout << "Empty Stack\n";
        return;
    }
    CarStack temp;
    temp.assignSize(size);
    while (top != -1)
    {
        int element = pop();
        cout << "\t"
             << element ;
        temp.push(element);
    }
    while (temp.top != -1)
    {
        int element = temp.pop();
        push(element);
    }
}

int CarStack::count()
{
    return top + 1;
}

int CarStack::pop(int carNumber)
{
    int element = 0, res;
    if (top == -1)
    {
        cout << "Empty Stack\n";
        return 0;
    }
    CarStack temp;
    temp.assignSize(size);
    element = pop();
    while (element != carNumber)
    {
        temp.push(element);
        element = pop();
        if (top == -1)
        {
            cout << "The Car Number is not found!";
            element = 0;
            break;
        }
    }
    res = element;
    while (temp.top != -1)
    {
        element = temp.pop();
        push(element);
    }
    return res;
}

int main()
{
    CarStack one;
    one.assignSize(10);
    one.push(1);
    one.push(2);
    one.push(3);
    one.push(4);
    one.push(5);
    one.push(6);
    one.display();
    one.pop(3);
    one.display();
    one.pop(4);
    one.display();
}
