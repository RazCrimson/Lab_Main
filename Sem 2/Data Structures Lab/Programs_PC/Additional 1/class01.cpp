#include <iostream>

using namespace std;

template <class T>
class SinglyLinkedList;

template <class T>
class Node
{
    T data;
    Node<T> *next;
    friend class SinglyLinkedList<T>;

public:
    Node() : data(NULL), next(NULL) {}
    Node(T key) : data(key), next(NULL) {}
    Node(const Node &copy) : data(copy.data), next(copy.next) {}
};

template <class T>
class SinglyLinkedList
{
    Node<T> *head;

public:
    SinglyLinkedList();
    SinglyLinkedList(int numberOfElements);
    void insertBeginning(Node<T> data);
    void insertEnd(Node<T> data);
    bool deleteFirst();
    bool deleteEnd();

    bool swap(int p, int n);
    void display();
};

template <class T>
SinglyLinkedList<T>::SinglyLinkedList()
{
    head = NULL;
}

template <class T>
void SinglyLinkedList<T>::display()
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
SinglyLinkedList<T>::SinglyLinkedList(int numberOfElements)
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
void SinglyLinkedList<T>::insertBeginning(Node<T> data)
{
    Node<T> *element = new Node<T>(data);
    element->next = head;
    head = element;
}

template <class T>
void SinglyLinkedList<T>::insertEnd(Node<T> data)
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
bool SinglyLinkedList<T>::deleteFirst()
{
    if (head == NULL)
        return false;
    Node<T> *ptr = head;
    head = head->next;
    delete ptr;
}

template <class T>
bool SinglyLinkedList<T>::deleteEnd()
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
bool SinglyLinkedList<T>::swap(Node<T> * p1, Node<T>* p2)
{
    Node<T> *t1, *t2;
    if (p1 != NULL)
        t1 = p1->next;
    else
        t1 = head;
    if (p2 != NULL)
        t2 = p2->next;
    else
        t2 = head;

    

    
}

int main()
{
    int ch, element;
    SinglyLinkedList<int> list;
    while (1)
    {
        cout << "\n1. Insert a new node at beginning of  the list\n"
                "2. Insert a new node at end to the list\n"
                "3. Delete the first node of the list\n"
                "4. Delete the last node of the list\n"
                "0. Display the elements of the list\n"
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
            cout << "Enter the element : ";
            cin >> element;
            list.insertEnd(element);
            break;
        case 3:
            list.deleteFirst();
            break;

        case 4:
            list.deleteEnd();
            break;
        case 0:
            list.display();
            break;
        default:
            return 0;
        }
    }
}