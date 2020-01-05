#include <iostream>
#include <stdlib.h>

using namespace std;
struct Set
{
    int size, *ptr;
};

void display(struct Set a)
{
    if (a.size <= 0)
    {
        cout << "Error!! Size of the structure is Invalid";
        exit(0);
    }
    cout << "The Size of the Set is " << a.size << endl;
    for (int i = 0; i < a.size; i++)
        cout << a.ptr[i] << "\t";
    cout << endl;
}

struct Set *add(struct Set a, struct Set b)
{
    struct Set *c = (struct Set *)malloc(sizeof(struct Set));
    if (a.size <= 0 || b.size <= 0)
    {
        cout << "Error!! Size of the structure is Invalid";
        exit(0);
    }
    c->ptr = (int *)malloc(sizeof(int) * (a.size + b.size));
    c->size = a.size + b.size;
    for (int i = 0; i < a.size; i++)
        c->ptr[i] = a.ptr[i];
    for (int i = 0; i < b.size; i++)
        c->ptr[a.size + i] = b.ptr[i];

    for (int i = 0; i < c->size; i++)
        for (int j = 0; j < (c->size - i - 1); j++)
            if (c->ptr[j] > c->ptr[j + 1])
            {
                int temp;
                temp = c->ptr[j];
                c->ptr[j] = c->ptr[j + 1];
                c->ptr[j + 1] = temp;
            }
    for (int i = 0; i < c->size - 1; i++)
    {
        if (c->ptr[i] == c->ptr[i + 1])
        {
            for (int k = i; k < c->size - 1; k++)
                c->ptr[k] = c->ptr[k + 1];
            c->size--;
            i--;
        }
    }
    return c;
}
