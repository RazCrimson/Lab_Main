#include <iostream>

using namespace std;

template <class T>
class SinglyLinked;

template <class T>
class Node
{
    T data;
    Node<T> *next;
    friend class SinglyLinked<T>;

public:
    Node() : data(NULL), next(NULL) {}
    Node(T key) : data(key), next(NULL) {}
    Node(const Node &copy) : data(copy.data), next(copy.next) {}
};

template <class T>
class SinglyLinked
{
    Node<T> *head;

public:
    SinglyLinked();
    SinglyLinked(int numberOfElements);
    void insertBeginning(Node<T> data);
    void insertEnd(Node<T> data);
    bool insertAfterData(Node<T> target, Node<T> data);
    bool deleteFirst();
    bool deleteEnd();
    bool deleteAfterData(Node<T> target);
    void display();
};

template <class T>
SinglyLinked<T>::SinglyLinked()
{
    head = NULL;
}

template <class T>
void SinglyLinked<T>::display()
{
    if (head == NULL)
    {
        cout << "List is Empty!\n";
        return;
    }
    Node<T> *ptr = head;
    cout << "List : ";
    while (ptr != NULL)
    {
        cout << ptr->data << '\t';
        ptr = ptr->next;
    }
    cout << "\n";
}

template <class T>
SinglyLinked<T>::SinglyLinked(int numberOfElements)
{
    if (numberOfElements < 1)
    {
        head = NULL;
        return;
    }
    head = new Node<T>();
    Node<T> *ptr = head;
    for (int i = 1; i < numberOfElements; i++)
    {
        ptr->next = new Node<T>();
        ptr = ptr->next;
    }
    ptr->next = NULL;
}

template <class T>
void SinglyLinked<T>::insertBeginning(Node<T> data)
{
    Node<T> *element = new Node<T>(data);
    element->next = head;
    head = element;
}

template <class T>
bool SinglyLinked<T>::insertAfterData(Node<T> target, Node<T> data)
{
    Node<T> *element = new Node<T>(data);
    Node<T> *ptr = head;
    if (head != NULL)
    {
        while (ptr != NULL)
        {
            if (ptr->data == target.data)
            {
                element->next = ptr->next;
                ptr->next = element;
                return true;
            }
            ptr = ptr->next;
        }
    }
    cout << "Element is not found!\n";
    return false;
}

template <class T>
void SinglyLinked<T>::insertEnd(Node<T> data)
{
    Node<T> *element = new Node<T>(data);
    Node<T> *ptr = head;
    if (head == NULL)
    {
        head = element;
        head->next = NULL;
        return;
    }
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = element;
    element->next = NULL;
}

template <class T>
bool SinglyLinked<T>::deleteFirst()
{
    if (head == NULL)
        return false;
    Node<T> *ptr = head;
    head = head->next;
    delete ptr;
}

template <class T>
bool SinglyLinked<T>::deleteEnd()
{
    if (head == NULL)
        return false;
    else if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return true;
    }
    Node<T> *ptr = head;
    while (ptr->next->next != NULL)
    {
        ptr = ptr->next;
    }
    delete ptr->next;
    ptr->next = NULL;
}

template <class T>
bool SinglyLinked<T>::deleteAfterData(Node<T> target)
{
    Node<T> *ptr = head;
    if (head != NULL)
    {
        while (ptr->next != NULL)
        {
            if (ptr->data == target.data)
            {
                Node<T> *del = ptr->next;
                ptr->next = del->next;
                delete del;
                return true;
            }
            ptr = ptr->next;
        }
    }
    cout << "Element is not Found!\n";
    return false;
}

int main()
{
    int ch, element;
    SinglyLinked<int> list;
    while (1)
    {
        cout << "\n1. Insert a new node at beginning of  the list\n"
                "2. Insert a new node after the node which has the element 'e'\n"
                "3. Insert a new node at end to the list\n"
                "4. Delete the first node of the list\n"
                "5. Delete an existing node which is placed after the node which has the element 'e'\n"
                "6. Delete the last node of the list\n"
                "7. Display the elements of the list\n"
                "Other to Quit.\n"
                "Enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter the element : ";
            cin >> element;
            list.insertBeginning(element);
            break;
        case 2:
            int data;
            cout << "Enter the data to be inserted : ";
            cin >> data;
            cout << "Enter the element : ";
            cin >> element;
            list.insertAfterData(element, data);
            break;
        case 3:
            cout << "Enter the element : ";
            cin >> element;
            list.insertEnd(element);
            break;
        case 4:
            list.deleteFirst();
            break;
        case 5:
            cout << "Enter the element : ";
            cin >> element;
            list.deleteAfterData(element);
            break;
        case 6:
            list.deleteEnd();
            break;
        case 7:
            list.display();
            break;
        default:
            return 0;
        }
    }
}