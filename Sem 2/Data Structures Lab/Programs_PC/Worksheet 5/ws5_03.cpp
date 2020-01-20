#include <iostream>

using namespace std;

template <class T>
class DoubleStack
{
    T *stack;
    int top, end, size;

public:
    DoubleStack();
    DoubleStack(T[], int, int = 0);
    int push(T, int);
    T pop(int);
    void assignSize(int);
    void high();
    void low();
    ~DoubleStack();
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
DoubleStack<T>::~DoubleStack()
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
int DoubleStack<T>::push(T element, int ch)
{
    if (ch == 1)
    {
        if (top + 1 == end)
        {
            throw __throw_out_of_range;
            return -1;
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
            return -1;
        }
        else
        {
            end -= 1;
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
            return -1;
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
            return -1;
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
void DoubleStack<T>::high()
{
    if(top + 1 < (size - end))
        for (int i = end; i < size; i++)
            cout << stack[i] << "\t";
    else
    {
        for(int i = 0; i <= top;i++)
            cout << stack[i] << "\t";
    }
    
}

template <class T>
void DoubleStack<T>::low()
{
    if(top + 1 > (size - end))
        for (int i = end; i < size; i++)
            cout << stack[i] << "\t";
    else
    {
        for(int i = 0; i <= top;i++)
            cout << stack[i] << "\t";
    }
    
}

int main()
{
    DoubleStack<int> one;
    one.assignSize(10);
    one.push(1, 1);
    one.push(2, 1);
    one.push(3, 1);
    one.push(4, 1);
    one.push(5, 1);
    one.push(6, 0);
    one.push(7, 0);
    one.push(8, 0);
    one.push(9, 0);
    one.push(0, 0);
    cout<<endl;
    one.high();
    cout<<endl;
    one.low();
}