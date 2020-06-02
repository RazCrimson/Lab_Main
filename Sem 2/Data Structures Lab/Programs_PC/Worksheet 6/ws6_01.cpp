#include <iostream>
// yet to be completed

template <class T>
class Queue
{
    T *queue;
    int front, rear, size;

public:
    Queue();
    void assignSize(int length);
    void display();
    int count();
    bool enqueue(T element);
    T dequeue();
    ~Queue();
};

template <class T>
Queue<T>::Queue()
{
    queue = new T[0];
    front = -1;
    rear = -1;
    size = 0;
}

template <class T>
Queue<T>::~Queue()
{
    delete[] queue;
}

template <class T>
void Queue<T>::assignSize(int length)
{
    queue = new T[length];
    front = -1;
    rear = -1;
    size = length;
}

template <class T>
int Queue<T>::count()
{
    return rear - front;
}

template <class T>
bool Queue<T>::enqueue(T element)
{
    if (rear + 1 == size)
    {
        //std::cout << "Queue Full!\n";
        return false;
    }
    rear += 1;
    queue[rear] = element;
    return true;
}

template <class T>
T Queue<T>::dequeue()
{
    if (front == rear)
    {
        //std::cout << "Queue Empty!\n";
        return -1;
    }
    front += 1;
    return queue[front];
}

template <class T>
void Queue<T>::display()
{
    for (int i = front + 1; i <= rear; i++)
        std::cout << queue[i] << "\t";
}

class WaitingLine
{
    Queue<int> *queues = new Queue<int>[3]();

    public:
    WaitingLine()
    {
        for (int i = 0; i < 3; i++)
            queues[i].assignSize(30);
    }  

    bool insert(int element, int randomNumber)
    {
        randomNumber = randomNumber % 3;
        if(randomNumber == 0)
            return queues[1].enqueue(element);
        else if(randomNumber == 1)
            return queues[2].enqueue(element);
        else
            return queues[3].enqueue(element);
    }

    void display()
    {
        for(int i = 0; i < 3; ++i)
        {
            int count = 0;
            Queue<int> temp;
            temp.assignSize(30);
            int element = queues[i].dequeue();
            while( element != -1)
            {
                temp.enqueue(element);
                element = queues[i].dequeue();
            }
        }
    }



};