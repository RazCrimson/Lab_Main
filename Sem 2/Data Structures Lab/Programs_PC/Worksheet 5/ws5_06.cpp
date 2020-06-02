#include <iostream>

using namespace std;

template <class T>
class CircularQueue
{
    T *queue;
    int front, rear, size, elements;

public:
    CircularQueue();
    void assignSize(int length);
    void display();
    int count();
    int enqueue(T element);
    T dequeue();
    ~CircularQueue();
};

template <class T>
CircularQueue<T>::CircularQueue()
{
    queue = new T[0];
    front = -1;
    rear = -1;
    size = 0;
    elements = 0;
}

template <class T>
CircularQueue<T>::~CircularQueue()
{
    delete [] queue;
}

template <class T>
void CircularQueue<T>::assignSize(int length)
{
    queue = new T[length];
    front = -1;
    rear = -1;
    size = length;
    elements = 0;
}

template <class T>
int CircularQueue<T>::count()
{
    return elements;
}

template <class T>
int CircularQueue<T>::enqueue(T element)
{
    if (elements + 1 == size)
    {
        cout << "Circular Queue Full!\n";
        return -1;
    }
    rear += 1;
    rear %= size;
    elements++;
    queue[rear] = element;
    return 0;
}

template <class T>
T CircularQueue<T>::dequeue()
{
    if(front == rear)
    {
        cout << "Circular Queue Empty!\n";
        return -1;
    }
    front += 1;
    front %= size;
    elements--;
    return queue[front];
}

template <class T>
void CircularQueue<T>::display()
{
    for(int i = 0; i < elements; i++)
        cout << queue[(front + i + 1)%size] << "\t";
}


int main()
{
    CircularQueue<int> s1;
    int size, ch, element;
    cout << "Enter the max size of Circular Queue : ";
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
