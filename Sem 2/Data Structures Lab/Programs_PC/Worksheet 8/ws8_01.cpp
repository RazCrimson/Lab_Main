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
    Node() : data(0), next(NULL) {}
    Node(T key) : data(key), next(NULL) {}
    Node(const Node &copy) : data(copy.data), next(copy.next) {}
};

template <class T>
class SinglyLinkedList
{
    Node<T> *head;

public:
    SinglyLinkedList();
    SinglyLinkedList(SinglyLinkedList<T> &list);
    SinglyLinkedList<T> &operator+(SinglyLinkedList<T> &list);
    SinglyLinkedList<T> &operator=(SinglyLinkedList<T> &list);
    ~SinglyLinkedList();

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
    SinglyLinkedList<T> &copy();
    SinglyLinkedList<T> &concatenate(SinglyLinkedList<T> &list);
    SinglyLinkedList<T> &combine(SinglyLinkedList<T> &list);
    SinglyLinkedList<T> &set(SinglyLinkedList<T> &list);
    SinglyLinkedList<T> &intersection(SinglyLinkedList<T> &list);
};

template <class T>
SinglyLinkedList<T>::SinglyLinkedList()
{
    head = NULL;
}

template <class T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
    free();
    delete this;
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
SinglyLinkedList<T>::SinglyLinkedList(SinglyLinkedList<T> &list)
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
SinglyLinkedList<T> &SinglyLinkedList<T>::operator=(SinglyLinkedList<T> &list)
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
SinglyLinkedList<T> &SinglyLinkedList<T>::operator+(SinglyLinkedList<T> &list)
{
    SinglyLinkedList<T> *ptr = new SinglyLinkedList<T>(*this);
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
    head = NULL;
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

template <class T>
bool SinglyLinkedList<T>::deleteNth(int n)
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
int SinglyLinkedList<T>::numberOfElements()
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
void SinglyLinkedList<T>::append(Node<T> data)
{
    insertEnd(data);
}

template <class T>
SinglyLinkedList<T>& SinglyLinkedList<T>::concatenate(SinglyLinkedList<T> &list)
{
    *this = *this + list;
    return *this;
}

template <class T>
void SinglyLinkedList<T>::delete_every_nth(int n)
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
bool SinglyLinkedList<T>::insertAfterNth(int n, Node<T> data)
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
bool SinglyLinkedList<T>::moveNode(int p, int n)
{
    Node<T> *ptr = head;
    if (head == NULL || n < 1)
        return false;
    // TODO: node(p) - p refers to position index or the data?
}

template <class T>
SinglyLinkedList<T> &SinglyLinkedList<T>::copy()
{
    return *(new SinglyLinkedList<T>(*this));
}

template <class T>
SinglyLinkedList<T> &SinglyLinkedList<T>::combine(SinglyLinkedList<T> &list)
{
    this->sort();
    list.sort();
    SinglyLinkedList<T> *ptr = new SinglyLinkedList<T>();
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
SinglyLinkedList<T> &SinglyLinkedList<T>::set(SinglyLinkedList<T> &list)
{
    SinglyLinkedList<T> *ptr = new SinglyLinkedList(*this);
    ptr->concatenate(list);
    ptr->sort();
    if (ptr->head == NULL)
        return *ptr;
    Node<T> *cpy, *tmp = ptr->head;
    while (tmp->next != NULL)
    {
        if (tmp->data == tmp->next->data)
        {
            cpy = tmp->next;
            tmp->next = tmp->next->next;
            delete cpy;
        }
        else
            tmp = tmp->next;
    }
    return *ptr;
}

template <class T>
SinglyLinkedList<T> &SinglyLinkedList<T>::intersection(SinglyLinkedList<T> &list)
{
    if (head == NULL || list.head == NULL)
        return *(new SinglyLinkedList<T>());
    SinglyLinkedList<T> *ptr = new SinglyLinkedList(*this);
    ptr->insertBeginning(-1);
    ptr->concatenate(list);
    ptr->sort();
    Node<T> *cpy, *tmp = ptr->head;
    bool flg = false;
    while (tmp->next->next != NULL)
    {
        if (tmp->next->data == tmp->next->next->data)
        {
            if (!flg)
                flg = true;
            cpy = tmp->next;
            tmp->next = tmp->next->next;
            delete cpy;
        }
        else
        {
            if (flg)
            {
                tmp = tmp->next;
                flg = false;
            }
            else
            {
                cpy = tmp->next;
                tmp->next = tmp->next->next;
                delete cpy;
            }
        }
    }
    delete tmp->next;
    tmp->next = NULL;
    cpy = ptr->head;
    ptr->head = ptr->head->next;
    delete cpy;
    return *ptr;
}

int main()
{
    int ch, select = 0, element;
    SinglyLinkedList<int> list[5];

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
            cout << "Select the list : ";
            cin >> select;
            cout << "Append an element to the end of a list: ";
            cin >> element;
            list[select % 5].append(element);
            break;
        case 2:
            list[0].concatenate(list[1]);
            break;
        case 3:
            cout << "Select the list : ";
            cin >> select;
            list[select % 5].free();
            break;
        case 4:
            cout << "Select the list : ";
            cin >> select;
            list[select % 5].reverse();
            break;
        case 5:
            cout << "Select the list : ";
            cin >> select;
            list[select % 5].deleteEnd();
            break;
        case 6:
            cout << "Select the list : ";
            cin >> select;
            cout << "Enter the value of n: ";
            cin >> element;
            list[select % 5].deleteNth(element);
            break;
        case 7:
            list[3] = list[0].combine(list[1]);
            break;
        case 8:
            list[4] = list[0].set(list[1]);
            break;
        case 9:
            list[5] = list[0].intersection(list[1]);
            break;
        case 10:
            int data;
            cout << "Select the list : ";
            cin >> select;
            cout << "Enter the value of n: ";
            cin >> element;
            cout << "Enter the value of data ";
            cin >> data;
            list[select % 5].insertAfterNth(element, data);
            break;
        case 11:
            cout << "Select the list : ";
            cin >> select;
            cout << "Enter the value of n: ";
            cin >> element;
            list[select % 5].delete_every_nth(element);
            break;
        case 12:
            cout << "Select the list : ";
            cin >> select;
            list[select % 5].sort();
            break;
        case 13:
            cout << "Select the list : ";
            cin >> select;
            cout << "\nThe sum is : " << list[select % 5].sum();
            break;
        case 14:
            cout << "Select the list : ";
            cin >> select;
            cout << "\nThe Number of elements is : " << list[select % 5].numberOfElements();
            break;
        case 15:
            //case
            break;
        case 16:
            cout << "Select the list : ";
            cin >> select;
            list[5] = list[select % 5];
        case 0:
            cout << "Select the list : ";
            cin >> select;
            list[select % 5].display();
            break;
        default:
            return 0;
        }
    }
}