#include <iostream>

using namespace std;

template <class T>
class DoublyLinkedList;

template <class T>
class Node
{
    T data;
    Node<T> *prev, *next;
    friend class DoublyLinkedList<T>;

public:
    Node() : data(NULL), prev(NULL), next(NULL) {}
    Node(T key) : data(key), prev(NULL), next(NULL) {}
    Node(const Node &copy) : data(copy.data), prev(copy.prev), next(copy.next) {}
};

template <class T>
class DoublyLinkedList
{
    Node<T> *head;

public:
    DoublyLinkedList();
    DoublyLinkedList(int numberOfElements);
    void insertBeginning(Node<T> data);
    void insertEnd(Node<T> data);
    bool insertBeforeData(Node<T> target, Node<T> data);
    bool insertAfterData(Node<T> target, Node<T> data);
    bool deleteFirst();
    bool deleteEnd();
    bool deleteBeforeData(Node<T> target);
    bool deleteAfterData(Node<T> target);
    void display();
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    head = NULL;
}

template <class T>
void DoublyLinkedList<T>::display()
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
DoublyLinkedList<T>::DoublyLinkedList(int numberOfElements)
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
    head->prev = NULL;
}

template <class T>
void DoublyLinkedList<T>::insertBeginning(Node<T> data)
{
    Node<T> *element = new Node<T>(data);
    if (head == NULL)
    {
        head = element;
        head->prev = NULL;
        head->next = NULL;
        return;
    }
    element->next = head;
    head->prev = element;
    element->prev = NULL;
    head = element;
}

template <class T>
bool DoublyLinkedList<T>::insertBeforeData(Node<T> target, Node<T> data)
{
    Node<T> *element = new Node<T>(data);
    Node<T> *ptr = head;
    if (head != NULL)
    {
        while (ptr != NULL)
        {
            if (ptr->data == target.data)
            {
                element->next = ptr;
                element->prev = ptr->prev;
                if (ptr == head)
                    head = element;
                else
                    ptr->prev->next = element;
                ptr->prev = element;
                return true;
            }
            ptr = ptr->next;
        }
    }
    cout << "Element is not found!\n";
    return false;
}

template <class T>
bool DoublyLinkedList<T>::insertAfterData(Node<T> target, Node<T> data)
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
                element->prev = ptr;
                if (ptr->next != NULL)
                    ptr->next->prev = element;
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
void DoublyLinkedList<T>::insertEnd(Node<T> data)
{
    Node<T> *element = new Node<T>(data);
    Node<T> *ptr = head;
    if (head == NULL)
    {
        head = element;
        head->prev = NULL;
        head->next = NULL;
        return;
    }
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = element;
    element->prev = ptr;
    element->next = NULL;
}

template <class T>
bool DoublyLinkedList<T>::deleteFirst()
{
    if (head == NULL)
        return false;
    Node<T> *ptr = head;
    head = head->next;
    if( head != NULL)
        head->prev = NULL;
    delete ptr;
    return true;
}

template <class T>
bool DoublyLinkedList<T>::deleteEnd()
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
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->prev->next = NULL;
    delete ptr->next;
    return true;
}

template <class T>
bool DoublyLinkedList<T>::deleteBeforeData(Node<T> target)
{
    Node<T> *ptr = head;
    if (head != NULL)
    {
        while (ptr->next != NULL)
        {
            if (ptr->data == target.data)
            {
                Node<T> *del = ptr->prev;
                if (del == NULL)
                    break;
                else if (del == NULL)
                {
                    head = ptr;
                    head->prev = NULL;
                }
                else
                {
                    ptr->prev = del->prev;
                    ptr->prev->next = ptr;
                }
                delete del;
                return true;
            }
            ptr = ptr->next;
        }
    }
    cout << "Element is not Found!\n";
    return false;
}

template <class T>
bool DoublyLinkedList<T>::deleteAfterData(Node<T> target)
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
                if (ptr->next != NULL)
                    ptr->next->prev = ptr;
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
    int ch, element, data;
    DoublyLinkedList<int> list;
    while (1)
    {
        cout << "\n1. Insert a new node at beginning of  the list\n"
                "2. Insert a new node before the node which has the element 'e'\n"
                "3. Insert a new node after the node which has the element 'e'\n"
                "4. Insert a new node at end to the list\n"
                "5. Delete the first node of the list\n"
                "6. Delete an existing node which is placed before the node which has the element 'e'\n"
                "7. Delete an existing node which is placed after the node which has the element 'e'\n"
                "8. Delete the last node of the list\n"
                "9. Display the elements of the list\n"
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
            cout << "Enter the data to be inserted : ";
            cin >> data;
            cout << "Enter the element : ";
            cin >> element;
            list.insertBeforeData(element, data);
            break;
        case 3:
            cout << "Enter the data to be inserted : ";
            cin >> data;
            cout << "Enter the element : ";
            cin >> element;
            list.insertAfterData(element, data);
            break;
        case 4:
            cout << "Enter the element : ";
            cin >> element;
            list.insertEnd(element);
            break;
        case 5:
            list.deleteFirst();
            break;
        case 6:
            cout << "Enter the element : ";
            cin >> element;
            list.deleteBeforeData(element);
            break;
        case 7:
            cout << "Enter the element : ";
            cin >> element;
            list.deleteAfterData(element);
            break;
        case 8:
            list.deleteEnd();
            break;
        case 9:
            list.display();
            break;
        default:
            return 0;
        }
    }
}