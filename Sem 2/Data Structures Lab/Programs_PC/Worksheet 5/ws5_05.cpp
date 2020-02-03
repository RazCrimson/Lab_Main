#include <iostream>

using namespace std;

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
    int enqueue(T element);
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
    delete [] queue;
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
int Queue<T>::enqueue(T element)
{
    if (rear + 1 == size)
    {
        cout << "Queue Full!\n";
        return -1;
    }
    rear +=1;
    queue[rear] = element;
    return 0;
}

template <class T>
T Queue<T>::dequeue()
{
    if(front == rear)
    {
        cout << "Queue Empty!\n";
        return -1;
    }
    front +=1;
    return queue[front];
}

template <class T>
void Queue<T>::display()
{
    for(int i = front  + 1; i <= rear; i++)
        cout << queue[i] << "\t";
}


int main()
{
    Queue<int> s1;
    int size, ch, element;
    cout << "Enter the max size of Queue : ";
    cin>>size;
    s1.assignSize(size);
    while (size > 0)
    {
        cout << "\n\nQueue Menu\n"
             << "1.Enqueue\n2.Dequeue\n3.Count\n"
             << "4.Display\n"
             << "Other to quit\n"
             << "Enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter the element : ";
            cin >> element;
            s1.enqueue(element);
            break;
        case 2:
            element = s1.dequeue();
            if(element != -1)
                cout<<"The element is " << element;
            break;
        case 3:
            cout << "The count is " << s1.count();
            break;
        case 4:
            s1.display();
            break;
        default:
            size = 0;
        }
    }
    return 0;
}
