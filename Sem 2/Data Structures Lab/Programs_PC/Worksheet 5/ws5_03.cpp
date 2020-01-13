#include <iostream>
#include "Stack.hpp"

using namespace std;

template <class T>
class DoubleStack
{
    T *stack;
    int top, end, size;

public:
    DoubleStack();
    DoubleStack(T[], int, int = 0);
    int push(T,int);
    T pop(int);
    int count();
    void assignSize(int);
    void displayFromTop();
    void displayFromBottom();
    ~Stack();
};

template <class T>
DoubleStack<T>::DoubleStack()
{
    top = -1;
    stack = new T[0]();
    size = 0;
    end = 0;
}

template <class T>
DoubleStack<T>::DoubleStack(T arr[], int len, int max)
{
    if (max == 0)
        max = len;
    stack = new T[max]();
    size = max;
    end = max;
    top = -1;
    for (int i = 0; i < len; i++)
        push(arr[i]);
}

template <class T>
DoubleStack<T>::~Stack()
{
    delete[] stack;
}

template <class T>
void DoubleStack<T>::assignSize(int max)
{
    delete[] stack;
    stack = new T[size]();
    top = -1;
    size = max;
    end = max;
}

template <class T>
int DoubleStack<T>::push(T element,int ch)
{
    if (ch == 1)
    {
        if (top + 1 == end)
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
    else
    {
        if (end - 1 == top)
        {
            throw __throw_out_of_range;
            return 0;
        }
        else
        {
            end = 1;
            stack[end] = element;
            return 0;
        }
    }
}

template <class T>
T DoubleStack<T>::pop(int ch)
{
    if (ch == 1)
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
    else
    {
        if (end == size)
        {
            throw __throw_out_of_range;
            return 0;
        }
        else
        {
            T element = stack[end];
            end += 1;
            return element;
        }
    }
}

template <class T>
void DoubleStack<T>::displayFromTop()
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
        T element = pop(1);
        cout << "\n"
             << element;
        temp.push(element);
    }
    while (temp.top != -1)
    {
        T element = temp.pop();
        push(element);
    }
    while(end != size){
        T element = pop(2);
        cout << "\n"
             << element;
        temp.push(element);
    }
}

// need work