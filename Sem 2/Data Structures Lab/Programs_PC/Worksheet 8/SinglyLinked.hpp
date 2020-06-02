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
    Node() : data(0), next(NULL) {}
    Node(T key) : data(key), next(NULL) {}
    Node(const Node &copy) : data(copy.data), next(copy.next) {}
};

template <class T>
class SinglyLinked
{
    Node<T> *head;

public:
    SinglyLinked();
    SinglyLinked(SinglyLinked<T> &list);
    SinglyLinked<T> &operator+(SinglyLinked<T> &list);
    SinglyLinked<T> &operator=(SinglyLinked<T> &list);
    ~SinglyLinked();

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
    void delete_every_nth(int n = 2);
    bool insertAfterNth(int n, Node<T> data);
    bool moveNode(int p, int n);
    SinglyLinked<T> &copy();
    SinglyLinked<T> &concatenate(SinglyLinked<T> &list);
    SinglyLinked<T> &combine(SinglyLinked<T> &list);
    SinglyLinked<T> &set(SinglyLinked<T> &list);
    SinglyLinked<T> &intersection(SinglyLinked<T> &list);
};

template <class T>
SinglyLinked<T>::SinglyLinked()
{
    head = NULL;
}

template <class T>
SinglyLinked<T>::~SinglyLinked()
{
    free();
    delete this;
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
SinglyLinked<T>::SinglyLinked(SinglyLinked<T> &list)
{
    if (list.head == NULL)
    {
        head = NULL;
        return;
    }
    Node<T> *ptr = list.head;
    head = new Node<T>(ptr->data);
    Node<T> *tmp = head;
    while (ptr->next != NULL)
    {
        tmp->next = new Node<T>(ptr->next->data);
        tmp = tmp->next;
        ptr = ptr->next;
    }
}

template <class T>
SinglyLinked<T> &SinglyLinked<T>::operator=(SinglyLinked<T> &list)
{
    if (this->head == list.head)
        return *this;
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
SinglyLinked<T> &SinglyLinked<T>::operator+(SinglyLinked<T> &list)
{
    SinglyLinked<T> *ptr = new SinglyLinked<T>(*this);
    if (list.head == NULL)
        return *this;

    Node<T> *temp = list.head;
    Node<T> *tmp = head;

    if (head == NULL)
    {
        head = new Node<T>(temp->data);
        tmp = head;
        temp = temp->next;
    }

    while (tmp->next != NULL)
        tmp = tmp->next;

    while (temp != NULL)
    {
        tmp->next = new Node<T>();
        tmp = tmp->next;
        tmp->data = temp->data;
        temp = temp->next;
    }
    tmp->next = NULL;
    return *this;
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

template <class T>
T SinglyLinked<T>::sum()
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
void SinglyLinked<T>::sort()
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
void SinglyLinked<T>::free()
{
    Node<T> *ptr = head;
    Node<T> *temp = NULL;
    while (ptr != NULL)
    {
        temp = ptr;
        ptr = ptr->next;
        delete temp;
    }
    head = NULL;
}

template <class T>
bool SinglyLinked<T>::reverse()
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

template <class T>
bool SinglyLinked<T>::deleteNth(int n)
{
    if (head == NULL)
        return false;
    Node<T> *tmp, *ptr = head;
    while (n-- > 2)
    {
        ptr = ptr->next;
        if (ptr == NULL)
            return false;
    }
    tmp = ptr->next;
    ptr->next = tmp->next;
    delete tmp;
    return true;
}

template <class T>
int SinglyLinked<T>::numberOfElements()
{
    Node<T> *ptr = head;
    int count = 0;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        count++;
    }
    return count;
}

template <class T>
void SinglyLinked<T>::append(Node<T> data)
{
    insertEnd(data);
}

template <class T>
SinglyLinked<T> &SinglyLinked<T>::concatenate(SinglyLinked<T> &list)
{
    *this = *this + list;
    return *this;
}

template <class T>
void SinglyLinked<T>::delete_every_nth(int n)
{
    /* 
        Args: n = 1 to INT_MAX
        Deletes the nth elements in the linked list
    */
    if (n == 1)
        free();
    else
    {

        Node<T> *cpy, *ptr = head;
        while (ptr != NULL)
        {
            for (int i = 1; i < n - 1; i++)
            {
                if (ptr->next == NULL)
                    return;
                ptr = ptr->next;
            }
            if (ptr->next == NULL)
                break;
            cpy = ptr->next;
            ptr->next = ptr->next->next;
            ptr = ptr->next;
            delete cpy;
        }
    }
}

template <class T>
bool SinglyLinked<T>::insertAfterNth(int n, Node<T> data)
{
    Node<T> *ptr = head;
    Node<T> *tmp = new Node<T>(data.data);
    if (head == NULL || n < 1)
        return false;
    while (n > 1)
    {
        ptr = ptr->next;
        n--;
        if (ptr == NULL)
            return false;
    }
    tmp->next = ptr->next;
    ptr->next = tmp;
    return true;
}

template <class T>
bool SinglyLinked<T>::moveNode(int p, int n)
{
    Node<T> *ptr, *tmp, dummy;
    dummy.next = head;
    ptr = &dummy;
    if (head == NULL || p < 1 || n < 1 || n + p > numberOfElements())
        return false;
    for (int i = 0; i < p; i++)
        ptr = ptr->next;
    tmp = ptr->next;
    if (p == 1)
        head = ptr->next->next;
    else
        ptr->next = ptr->next->next;
    insertAfterNth(n + p, *tmp);
    delete tmp;
}

template <class T>
SinglyLinked<T> &SinglyLinked<T>::copy()
{
    return *(new SinglyLinked(*this));
}

template <class T>
SinglyLinked<T> &SinglyLinked<T>::combine(SinglyLinked<T> &list)
{
    this->sort();
    list.sort();
    SinglyLinked<T> *ptr = new SinglyLinked<T>();
    Node<T> *t1, *t2, *t3;
    t1 = head;
    t2 = list.head;
    t3 = new Node<T>();
    ptr->head = t3;
    while (t1 != NULL && t2 != NULL)
    {
        if (t1->data > t2->data)
        {
            t3->next = t2;
            t2 = t2->next;
        }
        else
        {
            t3->next = t1;
            t1 = t1->next;
        }
        t3 = t3->next;
    }

    while (t1 != NULL)
    {
        t3->next = t1;
        t1 = t1->next;
        t3 = t3->next;
    }
    while (t2 != NULL)
    {
        t3->next = t2;
        t2 = t2->next;
        t3 = t3->next;
    }
    t3 = ptr->head;
    ptr->head = ptr->head->next;
    delete t3;
    list.head = head;
    this->head = NULL;
    return *ptr;
}

template <class T>
SinglyLinked<T> &SinglyLinked<T>::set(SinglyLinked<T> &list)
{
    SinglyLinked<T> result = new SinglyLinked<T>();
    SinglyLinked<T> list1 = *this;
    SinglyLinked<T> list2 = list;
    list1.sort();
    list2.sort();
    Node<T> *t1, *t2, *t3;
    t1 = list1.head;
    t2 = list2.head;
    while (t1 != NULL || t2 != NULL)
    {
        Node<T> *temp = new Node<T>();
        if (t1->data < t2->data)
        {
            temp->data = t1->data;
            t1 = t1->next;
        }
        else if (t2->data < t1->data)
        {
            temp->data = t2->data;
            t2 = t2->next;
        }
        else
        {
            temp->data = t1->data;
            t1 = t1->next;
            t2 = t2->next;
        }
        if (result->head == NULL)
            result->head = temp;
        else
            t3->next = temp;
        t3 = temp;
    }
    while (t1 != NULL)
    {
        Node<T> *temp = new Node<T>();
        temp->data = t1->data;
        t1 = t1->next;
        if (result->head == NULL)
            result->head = temp;
        else
            t3->next = temp;
        t3 = temp;
    }
    while (t2 != NULL)
    {
        Node<T> *temp = new Node<T>();
        temp->data = t2->data;
        t2 = t2->next;
        if (result->head == NULL)
            result->head = temp;
        else
            t3->next = temp;
        t3 = temp;
    }
    return result;
}

template <class T>
SinglyLinked<T>& SinglyLinked<T>::intersection(SinglyLinked<T> &list)
{
    SinglyLinked<T> result = new SinglyLinked<T>();
    SinglyLinked<T> list1 = *this;
    SinglyLinked<T> list2 = list;
    list1.sort();
    list2.sort();
    Node<T> *t1, *t2, *t3;
    t1 = list1.head;
    t2 = list2.head;
    while (t1 != NULL || t2 != NULL)
    {
        Node<T> *temp = new Node<T>();
        if (t1->data < t2->data)
        {
            temp->data = t1->data;
            t1 = t1->next;
        }
        else if (t2->data < t1->data)
        {
            temp->data = t2->data;
            t2 = t2->next;
        }
        else
        {
            temp->data = t1->data;
            t1 = t1->next;
            t2 = t2->next;
        }
        if (result->head == NULL)
            result->head = temp;
        else
            t3->next = temp;
        t3 = temp;
    }
    delete list1, list2;
    return result;
}