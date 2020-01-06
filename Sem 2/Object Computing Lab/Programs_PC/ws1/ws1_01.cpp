#include<iostream>

using namespace std;
struct set
{
    int size;
    int *p;
};

void read(struct set &s)
{
    cout << "Enter the number of elements: ";
    cin >> s.size;
    cout << "Enter the elements of the array:\n";
    s.p = new int[s.size];
    for (int i = 0; i < s.size; i++)
        cin >> s.p[i];
}

void display(struct set &s)
{
    cout << "The elements of array are\n";
    for (int i = 0; i < s.size; i++)
        cout << s.p[i] << "\n";
}
struct set merge(struct set &x, struct set &y)
{
    int i, j, k;
    struct set z;
    z.size = x.size + y.size;
    z.p = new int[z.size];
    for (i = 0; i < x.size; i++)
        z.p[i] = x.p[i];
    for (i = 0; i < y.size; i++)
        z.p[i + x.size] = y.p[i];
    for (i = 0; i < z.size - 1; i++)
    {
        for (j = i + 1; j < z.size; j++)
        {
            if (z.p[i] == z.p[j])
            {
                for (k = j; k < z.size - 1; k++)
                    z.p[k] = z.p[k + 1];
                j--;
                z.size--;
            }
        }
    }
    return z;
}
int main()
{
    struct set s1, s2, s3;
    cout << "Enter the details of first array\n";
    read(s1);
    cout << "Enter the details of second array\n";
    read(s2);
    s3 = merge(s1, s2);
    display(s3);
}
