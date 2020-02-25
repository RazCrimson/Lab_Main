#include <iostream>

using namespace std;

class SinglyLinkedList;

class Node
{
    int data;
    Node *next;
    friend class SinglyLinkedList;

public:
    Node() : data(0), next(NULL) {}
    Node(int key) : data(key), next(NULL) {}
    Node(const Node &copy) : data(copy.data), next(copy.next) {}
};

class SinglyLinkedList
{
    Node *head;

public:
    SinglyLinkedList();
    SinglyLinkedList(SinglyLinkedList &list);
    SinglyLinkedList &operator+(SinglyLinkedList &list);
    SinglyLinkedList &operator=(SinglyLinkedList &list);
    ~SinglyLinkedList();

    void insertBeginning(Node data);
    void insertEnd(Node data);
    bool insertAfterData(Node target, Node data);
    bool deleteFirst();
    bool deleteEnd();
    bool deleteAfterData(Node target);
    void display();

    int sum();
    void sort();
    void free();
    bool reverse();
    bool deleteNth(int n);
    int numberOfElements();
    void append(Node data);
    void delete_every_nth(int n = 2);
    bool insertAfterNth(int n, Node data);
    bool moveNode(int p, int n);
    SinglyLinkedList &copy();
    SinglyLinkedList &concatenate(SinglyLinkedList &list);
    SinglyLinkedList &combine(SinglyLinkedList &list);
    SinglyLinkedList &set(SinglyLinkedList &list);
    SinglyLinkedList &intersection(SinglyLinkedList &list);
};

SinglyLinkedList::SinglyLinkedList()
{
    head = new Node(0);
}

SinglyLinkedList::~SinglyLinkedList()
{
    free();
    delete head;
    delete this;
}

void SinglyLinkedList::display()
{
    if (head == NULL)
    {
        cout << "List is Empty!\n";
        return;
    }
    Node *ptr = head;
    cout << "List : ";
    while (ptr != NULL)
    {
        cout << ptr->data << '\t';
        ptr = ptr->next;
    }
    cout << "\n";
}

SinglyLinkedList::SinglyLinkedList(SinglyLinkedList &list)
{
    if (list.head->next == NULL)
    {
        head = new Node(0);
        return;
    }
    Node *ptr = list.head->next;
    head = new Node(list.head->data);
    Node *tmp = head;
    while (ptr->next != NULL)
    {
        tmp->next = new Node(ptr->next->data);
        tmp = tmp->next;
        ptr = ptr->next;
    }
}

SinglyLinkedList &SinglyLinkedList::operator=(SinglyLinkedList &list)
{
    if (this->head == list.head)
        return *this;
    free();
    if (list.head->next == NULL)
    {
        head->data = 0;
        return *this;
    }
    head->data = list.head->data;
    Node *temp = list.head->next;
    Node *ptr = head;
    while (temp != NULL)
    {
        ptr->next = new Node();
        ptr = ptr->next;
        ptr->data = temp->data;
        temp = temp->next;
    }
    ptr->next = NULL;
    return *this;
}

SinglyLinkedList &SinglyLinkedList::operator+(SinglyLinkedList &list) // needs edit
{
    SinglyLinkedList *ptr = new SinglyLinkedList(*this);
    if (list.head->next == NULL)
        return *this;

    Node *temp = list.head->next;
    Node *tmp = head->next;

    while (tmp->next != NULL)
        tmp = tmp->next;

    while (temp != NULL)
    {
        tmp->next = new Node();
        tmp = tmp->next;
        tmp->data = temp->data;
        temp = temp->next;
    }
    tmp->next = NULL;
    head->data = numberOfElements();
    return *this;
}

void SinglyLinkedList::insertBeginning(Node data)
{
    Node *element = new Node(data);
    element->next = head->next;
    head->next = element;
    head->data += 1;
}

bool SinglyLinkedList::insertAfterData(Node target, Node data)
{
    Node *element = new Node(data);
    Node *ptr = head->next;
    if (head->next != NULL)
    {
        while (ptr != NULL)
        {
            if (ptr->data == target.data)
            {
                element->next = ptr->next;
                ptr->next = element;
                head->data += 1;
                return true;
            }
            ptr = ptr->next;
        }
    }
    cout << "Element is not found!\n";
    return false;
}

void SinglyLinkedList::insertEnd(Node data)
{
    Node *element = new Node(data);
    Node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = element;
    element->next = NULL;
    head->data += 1;
}

bool SinglyLinkedList::deleteFirst()
{
    if (head->next == NULL)
        return false;
    Node *ptr = head->next;
    head->next = head->next->next;
    head->data -= 1;
    delete ptr;
}

bool SinglyLinkedList::deleteEnd()
{
    if (head->next == NULL)
        return false;
    Node *ptr = head;
    while (ptr->next->next != NULL)
    {
        ptr = ptr->next;
    }
    delete ptr->next;
    ptr->next = NULL;
    head->data -= 1;
}

bool SinglyLinkedList::deleteAfterData(Node target)
{
    Node *ptr = head->next;
    if (head->next != NULL)
    {
        while (ptr->next != NULL)
        {
            if (ptr->data == target.data)
            {
                Node *del = ptr->next;
                ptr->next = del->next;
                delete del;
                head->data -= 1;
                return true;
            }
            ptr = ptr->next;
        }
    }
    cout << "Element is not Found!\n";
    return false;
}

int SinglyLinkedList::sum()
{
    int temp = 0;
    Node *ptr = head->next;
    while (ptr != NULL)
    {
        temp += ptr->data;
        ptr = ptr->next;
    }
    return temp;
}

void SinglyLinkedList::sort()
{
    if (head->next == NULL)
        return;
    Node *ptr, *end;
    int tmp;
    ptr = head->next;
    end = NULL;
    while (ptr->next != end)
    {
        while (ptr->next != end)
        {
            if (ptr->data > ptr->next->data)
            {
                tmp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = tmp;
            }
            ptr = ptr->next;
        }
        end = ptr;
        ptr = head->next;
    }
}

void SinglyLinkedList::free()
{
    Node *ptr = head->next;
    Node *temp = NULL;
    while (ptr != NULL)
    {
        temp = ptr;
        ptr = ptr->next;
        delete temp;
    }
    head->data = 0;
}

bool SinglyLinkedList::reverse()
{
    if (head->next == NULL || head->next->next == NULL)
        return false;
    Node *t1, *t2, *t3;
    t1 = head->next;
    t2 = t1->next;
    t1->next = NULL;
    while (t2 != NULL)
    {
        t3 = t2->next;
        t2->next = t1;
        t1 = t2;
        t2 = t3;
    }
    head->next = t1;
    return true;
}

bool SinglyLinkedList::deleteNth(int n)
{
    if (head->next == NULL)
        return false;
    Node *tmp, *ptr = head->next;
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

int SinglyLinkedList::numberOfElements()
{
    Node *ptr = head->next;
    int count = 0;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        count++;
    }
    return count;
}

void SinglyLinkedList::append(Node data)
{
    insertEnd(data);
}

SinglyLinkedList &SinglyLinkedList::concatenate(SinglyLinkedList &list) // edit +
{
    *this = *this + list;
    return *this;
}

void SinglyLinkedList::delete_every_nth(int n)
{
    /* 
        Args: n = 1 to INT_MAX
        Deletes the nth elements in the linked list
    */
    if (n == 1)
        free();
    else
    {

        Node *cpy, *ptr = head->next;
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
            head->data -= 1;
        }
    }
}

bool SinglyLinkedList::insertAfterNth(int n, Node data)
{
    Node *ptr = head->next;
    Node *tmp = new Node(data.data);
    if (head->next == NULL || n < 1)
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
    head->data += 1;
    return true;
}

bool SinglyLinkedList::moveNode(int p, int n)
{
    Node *ptr, *tmp, dummy;
    dummy.next = head->next;
    ptr = &dummy;
    if (head->next == NULL || p < 1 || n < 1 || n + p > numberOfElements())
        return false;
    for (int i = 0; i < p; i++)
        ptr = ptr->next;
    tmp = ptr->next;
    if (p == 1)
        head->next = ptr->next->next;
    else
        ptr->next = ptr->next->next;
    insertAfterNth(n + p, *tmp);
    delete tmp;
}

SinglyLinkedList &SinglyLinkedList::copy()
{
    return *(new SinglyLinkedList(*this));
}

SinglyLinkedList &SinglyLinkedList::combine(SinglyLinkedList &list) // needs check
{
    this->sort();
    list.sort();
    SinglyLinkedList *ptr = new SinglyLinkedList();
    Node *t1, *t2, *t3;
    t1 = head->next;
    t2 = list.head->next;
    t3 = new Node();
    ptr->head->next = t3;
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

SinglyLinkedList &SinglyLinkedList::set(SinglyLinkedList &list)
{
    SinglyLinkedList *result = new SinglyLinkedList();
    this->sort();
    list.sort();
    Node *t1 = head->next;
    Node *t2 = list.head->next;
    Node *t3 = result->head->next;
    while (t1 != NULL || t2 != NULL)
    {
        Node *temp = new Node();
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
        t3->next = temp;
        t3 = temp;
    }
    return *result;
}

SinglyLinkedList &SinglyLinkedList::intersection(SinglyLinkedList &list)
{
    //sdfghj
}

int main()
{
    int ch, select = 0, element;
    SinglyLinkedList list[6];

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
            list[select % 6].append(element);
            break;
        case 2:
            list[0].concatenate(list[1]);
            break;
        case 3:
            cout << "Select the list : ";
            cin >> select;
            list[select % 6].free();
            break;
        case 4:
            cout << "Select the list : ";
            cin >> select;
            list[select % 6].reverse();
            break;
        case 5:
            cout << "Select the list : ";
            cin >> select;
            list[select % 6].deleteEnd();
            break;
        case 6:
            cout << "Select the list : ";
            cin >> select;
            cout << "Enter the value of n: ";
            cin >> element;
            list[select % 6].deleteNth(element);
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
            list[select % 6].insertAfterNth(element, data);
            break;
        case 11:
            cout << "Select the list : ";
            cin >> select;
            cout << "Enter the value of n: ";
            cin >> element;
            list[select % 6].delete_every_nth(element);
            break;
        case 12:
            cout << "Select the list : ";
            cin >> select;
            list[select % 6].sort();
            break;
        case 13:
            cout << "Select the list : ";
            cin >> select;
            cout << "\nThe sum is : " << list[select % 6].sum();
            break;
        case 14:
            cout << "Select the list : ";
            cin >> select;
            cout << "\nThe Number of elements is : " << list[select % 6].numberOfElements();
            break;
        case 15:
            //case
            break;
        case 16:
            cout << "Select the list : ";
            cin >> select;
            list[5] = list[select % 6];
        case 0:
            cout << "Select the list : ";
            cin >> select;
            list[select % 6].display();
            break;
        default:
            return 0;
        }
    }
}
