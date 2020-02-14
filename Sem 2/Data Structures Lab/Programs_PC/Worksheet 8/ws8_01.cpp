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
    SinglyLinkedList(Node<T> &list_head);
    SinglyLinkedList(SinglyLinkedList<T> &list);
    SinglyLinkedList<T>& operator=(SinglyLinkedList<T> &list);
    SinglyLinkedList<T>& operator+(SinglyLinkedList<T> &list);

    void insertBeginning(Node<T> data);
    void insertEnd(Node<T> data);
    bool insertAfterData(Node<T> target, Node<T> data);
    bool deleteFirst();
    bool deleteEnd();
    bool deleteAfterData(Node<T> target);
    void display();

    T sum();
    void sort();
    void free();
    bool reverse();
    bool deleteNth(int n);
    int numberOfElements();
    void append(Node<T> data);
    void delete_every_nth(int n);
    bool insertAfterNth(int n, Node<T> data);
    bool moveNode(int n, Node<T> target);
    SinglyLinkedList<T> &copy();
    SinglyLinkedList<T> &concatenate(SinglyLinkedList<T> &list);
    SinglyLinkedList<T> &combine(SinglyLinkedList<T> &list);
    SinglyLinkedList<T> &set(const SinglyLinkedList<T> &list);
    SinglyLinkedList<T> &intersection(const SinglyLinkedList<T> &list);
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
SinglyLinkedList<T>::SinglyLinkedList(Node<T> &list_head)
{
    head = &list_head;
}

template <class T>
SinglyLinkedList<T>::SinglyLinkedList(SinglyLinkedList<T> &list)
{
   *(this) = list;
}

template <class T>
SinglyLinkedList<T>& SinglyLinkedList<T>::operator=(SinglyLinkedList<T> &list)
{
    free();
    if (list.head == NULL)
    {
        head = NULL;
        return *this;
    }
    head = new Node<T>();
    Node<T> *temp = list.head;
    Node<T> *ptr = head;
    while (temp != NULL)
    {
        ptr->next = new Node<T>();
        ptr = ptr->next;
        ptr->data = temp->data;
        temp = temp->next;
    }
    ptr->next = NULL;
    ptr = head;
    head = head->next;
    delete ptr;
    return *this;
}

template <class T>
SinglyLinkedList<T>& SinglyLinkedList<T>::operator+(SinglyLinkedList<T> &list)
{
    if( list.head == NULL)
        return *this;
    Node<T>* ptr = head;
    Node<T>* temp = list.head;

    while(ptr->next != NULL)
        ptr = ptr->next;

    while(temp != NULL)
    {
        ptr->next = new Node<T>();
        ptr = ptr->next;
        ptr->data = temp->data;
        temp = temp->next;
    }
    ptr->next = NULL;
    return *this;    
}

template <class T>
void SinglyLinkedList<T>::insertBeginning(Node<T> data)
{
    Node<T> *element = new Node<T>(data);
    element->next = head;
    head = element;
}

template <class T>
bool SinglyLinkedList<T>::insertAfterData(Node<T> target, Node<T> data)
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
bool SinglyLinkedList<T>::deleteAfterData(Node<T> target)
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

template <class T>
T SinglyLinkedList<T>::sum()
{
    T temp = 0;
    Node<T>* ptr = head;
    while(ptr != NULL)
    {
        temp += ptr->data;
        ptr = ptr->next;
    }
    return temp;
}

template <class T>
void SinglyLinkedList<T>::sort()
{

}


template <class T>
void SinglyLinkedList<T>::free()
{
    Node<T>* ptr = head;
    Node<T>* temp = NULL;
    while(ptr != NULL)
    {
        temp = ptr;
        ptr = ptr->next;
        delete temp;
    }
}