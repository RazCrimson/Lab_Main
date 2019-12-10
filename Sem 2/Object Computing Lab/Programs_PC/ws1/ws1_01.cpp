#include <iostream>
#include <stdlib.h>

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

struct Set* add(struct Set a,struct Set b)
{
    struct Set* c = (struct Set*)malloc(sizeof(struct Set));
    if (a.size <= 0 || b.size <= 0)
    {
        cout << "Error!! Size of the structure is Invalid";
        exit(0);
    }
    c->ptr = (int*)malloc(sizeof(int)*(a.size+b.size));
    c->size = a.size + b.size;
    for(int i = 0; i< a.size;i++)
        ptr[i] = a.ptr[i];
    for(int i = 0; i< b.size;i++)
        ptr[a.size+ i] = b.ptr[i];        
    for(int i=0;i<c->size;i++)
        for(int j=0;j<(c->size - i -1);j++)
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
    for(int i=0;i<c->size;i++)
    {
        for(int j=0;j<c->size - i;j++)
        {
            if(arr[i]==arr[j])
            {
                for (int k =i; k<n; k++)
                    arr[k]=arr[k+1];
                c->size--;
                i--; 
            }
        }
    }
    return &c;
}
