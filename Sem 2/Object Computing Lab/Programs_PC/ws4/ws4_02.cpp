#include <iostream>

using namespace std;

class Set
{
    int *ptr;
    int length, count;

    void sort();

public:
    Set(int);
    void display();
    bool add(int);
    bool remove(int);
    Set operator|(Set &);
    Set operator&(Set &);
};

Set::Set(int n)
{
    ptr = new int[n]();
    count = 0;
    length = n;
}

bool Set::add(int x)
{
    if (count >= length)
        return false;
    for (int i = 0; i < count; i++)
        if (ptr[i] == x)
            return true;
    ptr[count] = x;
    count += 1;
    return true;
}

bool Set::remove(int x)
{
    if (count == 0)
        return false;
    for (int i = 0; i < count; i++)
    {
        if (ptr[i] == x)
        {
            for (int j = i; i < count - 1; i++)
            {
                ptr[i] = ptr[i + 1];
            }
            ptr[count] = 0;
            count -= 1;
            return true;
        }
    }
    return false;
}

void Set::sort()
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (ptr[j] > ptr[j + 1])
            {
                int temp = ptr[j];
                ptr[j] = ptr[j + 1];
                ptr[j + 1] = temp;
            }
        }
    }
}

Set Set::operator|(Set &b)
{
    Set res(count + b.count);
    for (int i = 0; i < count; i++)
        res.add(ptr[i]);
    for (int i = 0; i < b.count; i++)
        res.add(b.ptr[i]);
    return res;
}

Set Set::operator&(Set &b)
{
    Set *temp1, *temp2;
    if (count < b.count)
    {
        temp1 = this;
        temp2 = &b;
    }
    else
    {
        temp1 = &b;
        temp2 = this;
    }
    Set res(temp1->count);
    for (int i = 0; i < temp1->count; i++)
    {
        for (int j = 0; j < temp2->count; j++)
        {
            if (temp1->ptr[i] == temp2->ptr[j])
            {
                res.add(temp1->ptr[i]);
                break;
            }
        }
    }
    return res;
}

void Set::display()
{
    cout << "\nNumber of elements : " << count << endl;
    for (int i = 0; i < count; i++)
        cout << ptr[i] << "\t";
}

int main()
{
    Set a1(10), a2(10);
    a1.add(1);
    a1.add(2);
    a1.add(3);
    a1.add(4);
    a1.add(5);
    a1.add(6);
    a2.add(5);
    a2.add(6);
    a2.add(7);
    a2.add(8);
    a2.add(9);
    (a1 | a2).display();
    (a1 & a2).display();
}