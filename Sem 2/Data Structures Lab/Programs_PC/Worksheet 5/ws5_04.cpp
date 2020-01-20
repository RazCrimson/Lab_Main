#include <iostream>
#include "Stack.hpp"

using namespace std;

template <class T>
class CarStack : public Stack
{

public:
    CarStack();
    CarStack(T[],int,int = 0);
    T pop(int);
    /*int push(T);
    T pop();
    int count();
    void assignSize(int);
    void displayFromTop();
    void displayFromBottom();*/
};

/*
template <class T>
T CarStack<T>::pop(){
    return Stack::pop();
}

template <class T>
int CarStack<T>::push(T){
    return Stack::pop();
}
*/
template <class T>
CarStack<T>::CarStack():Stack{}
{
}

template <class T>
CarStack<T>::CarStack(T arr[],int len,int max):Stack{arr,len,max}
{
}

template <class T>
T CarStack<T>::pop(int carNumber)
{
    if (top == -1)
    {
        throw __throw_out_of_range;
        return 0;
    }
    else
    {
        int element, req;
        Stack<T> temp;
        temp.assignSize(size);
        try
        {
            do
            {
                element = pop();
                temp.push(element);
            } while (carNumber != element);
        }
        catch (const std::exception &e)
        {
            cout << "Car Number "<<carNumber << " Not found.";
            return -1;
        }
        req = temp.pop();
        try
        {
            element = temp.pop();
            while (element != -1) 
            {
                push(element);
            }
        }
        catch (const std::exception &e)
        {
        }
    }
}


int main()
{
    CarStack<int> one;
    one.Stack::assignSize(10);

}
///dgdgdgdgdfg