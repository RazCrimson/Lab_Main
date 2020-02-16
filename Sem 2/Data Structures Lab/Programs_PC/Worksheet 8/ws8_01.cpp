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
    SinglyLinkedList<T> &operator=(SinglyLinkedList<T> &list);
    SinglyLinkedList<T> &operator+(SinglyLinkedList<T> &list);

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
    void delete_every_nth(int n=2);
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
SinglyLinkedList<T> &SinglyLinkedList<T>::operator=(SinglyLinkedList<T> &list)
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
SinglyLinkedList<T> &SinglyLinkedList<T>::operator+(SinglyLinkedList<T> &list)
{
    if (list.head == NULL)
        return *this;
    Node<T> *ptr = head;
    Node<T> *temp = list.head;

    while (ptr->next != NULL)
        ptr = ptr->next;

    while (temp != NULL)
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
    Node<T> *ptr = head;
    while (ptr != NULL)
    {
        temp += ptr->data;
        ptr = ptr->next;
    }
    return temp;
}

template <class T>
void SinglyLinkedList<T>::sort()
{
    if (head == NULL)
        return;
    Node<T> *t, *end;
    T tmp;
    t = head;
    end = NULL;
    while (t->next != end)
    {
        while (t->next != end)
        {
            if (t->data > t->next->data)
            {
                tmp = t->data;
                t->data = t->next->data;
                t->next->data = tmp;
            }
            t = t->next;
            
        }
        end = t;
        t = head;
    }
}

template <class T>
void SinglyLinkedList<T>::free()
{
    Node<T> *ptr = head;
    Node<T> *temp = NULL;
    while (ptr != NULL)
    {
        temp = ptr;
        ptr = ptr->next;
        delete temp;
    }
}


template <class T>
bool SinglyLinkedList<T>::deleteNth(int n)
{
    if(head == NULL)
        return false;
    Node<T> *ptr = head;
    while (n-- > 1)
    {
        ptr = ptr->next;
        if(ptr == NULL)
            return false;
    }
    delete ptr;
    return true;
}

template <class T>
int SinglyLinkedList<T>::numberOfElements()
{
    Node<T> *ptr = head;
    int count = 0;
    while(ptr != NULL)
        ptr = ptr->next;
    return count;
}


template <class T>
void SinglyLinkedList<T>::append(Node<T> data)
{
    insertEnd(data);
}

template <class T>
void SinglyLinkedList<T>::delete_every_nth(int n)
{
    insertEnd(d
}


template <class T>
bool SinglyLinkedList<T>::reverse()
{
    if (head == NULL || head->next == NULL)
        return false;
    Node<T> *t1, *t2, *t3;
    t1 = head;
    t2 = t1->next;
    t1->next = NULL;
    while (t2 != NULL)
    {
        t3 = t2->next;
        t2->next = t1;
        t1 = t2;
        t2 = t3;
    }
    head = t1;
    return true;
}

int main()
{
    int ch, element;
    SinglyLinkedList<int> list;
    while (1)
    {
        cout << "1) Append an element to the end of a list\n"
                "2) Concatenate two lists\n"
                "3) Free all the nodes in a list\n"
                "4) Reverse a list, so that the last element becomes the first, and so on. \n"
                "5) Delete the last element from a list\n"
                "6) Delete the nth element from a list\n"
                "7) Combine two ordered lists into a single ordered list\n"
                "8) Form a list containing the union of the elements of two lists\n"
                "9) Form a list containing the intersection of the elements of two lists\n"
                "10) Insert an element after the nth element of a list\n"
                "11) Delete every second element from a list\n"
                "12) Place the elements of a list in increasing order\n"
                "13) Return the sum of the integers in a list\n"
                "14) Return the number of elements in a list\n"
                "15) Move node(p) forward n positions in a list\n"
                "16) Make a second copy of a list \n";

        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Append an element to the end of a list: ";
            cin >> element;
            list.insertEnd(element);
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
            list.reverse();
            break;
        case 5:
            cout << "Enter the element : ";
            cin >> element;
            list.deleteAfterData(element);
            break;
        case 6:
            list.deleteEnd();
            break;
        case 12:
            list.sort();
            list.display();
            break;
        case 0:
            list.display();
            break;

        //case
        default:
            exit(0);
        }
    }
}