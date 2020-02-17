#include <iostream>

class MyString
{
    char *ptr;
    unsigned length;
    unsigned calculateLength();

public:
    MyString();
    MyString(const char *string);
    MyString(unsigned len);
    ~MyString();
    bool operator==(const MyString &b);
    MyString operator+(const MyString &b);
    MyString &operator=(MyString &b);
    MyString &operator++();
    MyString &operator--();
    void display();
};

MyString::MyString()
{
    ptr = NULL;
    length = 0;
}

MyString::MyString(const char *string)
{
    length = 0;
    while (string[length] != '\0')
        length++;
    ptr = new char[length + 1]();
    for (int i = 0; i < length; i++)
        ptr[i] = string[i];
}

MyString::MyString(unsigned len)
{
    ptr = new char[len + 1]();
    length = len;
}

MyString::~MyString()
{
    delete[] ptr;
    length = 0;
}

bool MyString::operator==(const MyString &b)
{
    if (length != b.length)
        return false;
    for (int i = 0; i < length; i++)
        if (ptr[i] != b.ptr[i])
            return false;
    return true;
}

MyString MyString::operator+(const MyString &b)
{
    unsigned len = length + b.length - 1;
    char *tmp = new char[len]();
    for (int i = 0; i < length; i++)
        tmp[i] = ptr[i];
    for (int i = 0; i < b.length; i++)
        tmp[length + i] = b.ptr[i];
    tmp[length + b.length] = 0;
    return tmp;
}

MyString &MyString::operator=(MyString &b)
{
    delete [] ptr;
    length = b.length;
    ptr = new char[length];
    for (int i = 0; i < length; i++)
        ptr[i] = b.ptr[i];
}

MyString &MyString::operator++()
{
    for (int i = 0; i < length; i++)
        ptr[i]++;
    return *this;
}

MyString &MyString::operator--()
{
    for (int i = 0; i < length; i++)
        ptr[i]--;
    return *this;
}

void MyString::display()
{
    std::cout << ptr << "  Length : " << length;
}

int main()
{
    MyString s1("My name"), s2("Raz");
    (s1 + s2).display();
    MyString s3;
    s3 = s1;
    if (s3 == s1)
        std::cout << "same";
    return 0;
}