#include <iostream>

using namespace std;

template <class T>
class LinkedList;

template <class T>
class Node
{
    T data;
    Node *next;
    friend class LinkedList;

public:
    Node() : data(NULL), next(NULL) {}
    Node(T key) : data(key), next(NULL) {}
};

template <class T>
class LinkedList
{
    Node<T> *Head;

public:
    LinkedList();
    LinkedList(int numberOfElements);
    void insertBeginning(T element);
    void insertBeginning(Node<T> element);
    void insertEnd(T element);
    void insertEnd(Node<T> element);
    bool insertAfterData(T data, T element);
    bool insertAfterNode(Node<T> target, Node<T> element);
    bool deletefirst();
    bool deleteData();
    bool deleteAfterData(T element);
    void display();
};

template <class T>
LinkedList<T>::LinkedList()
{
    Head = NULL;
}

template <class T>
LinkedList<T>::LinkedList(int numberOfElements)
{
    if (numberOfElements < 1)
    {
        Head = NULL;
        return;
    }
    Head = new Node<T>();
    Node<T> *ptr = head;
    for (int i = 1; i < numberOfElements; i++)
    {
        ptr->next = new Node<T>();
        ptr = ptr->next;
    }
    ptr->next = NULL;
}

template <class T>
void LinkedList<T>::insertBeginning(T element)
{
    insertBeginning(Node<T>(element));
}

template <class T>
void LinkedList<T>::insertBeginning(Node<T> element)
{
    element->next = head;
    head = element;
}

template <class T>
void LinkedList<T>::insertEnd(T element)
{
    insertEnd(Node<T>(element));
}

template <class T>
void LinkedList<T>::insertBeginning(Node<T> element)
{
    element->next = head;
    head = element;
}

template <class T>
bool LinkedList<T>::insertAfterData(T data, T element)
{

}
