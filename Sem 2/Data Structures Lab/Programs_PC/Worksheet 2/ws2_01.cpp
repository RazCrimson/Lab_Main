#include <iostream>
#include <cstdlib>

using namespace std;

int *insert(int *arr, int *n, int index, int item)
{
    int len = *n;
    if (index < 0 || len <= 0)
    {
        cout << "Warning!!! Error in the insert function" << endl;
        exit(0);
    }
    arr = (int *)realloc(arr, sizeof(int) * len + 1);
    for (int i = len; i >= index; i--)
        arr[i + 1] = arr[i];
    arr[index] = item;
    *n += 1;
    return arr;
}

int *del(int *arr, int *n, int index)
{
    int len = *n;
    if (len <= 0 || index < 0)
    {
        cout << "Warning!!! Error in the delete function" << endl;
        exit(0);
    }
    for (int i = index; i < len - 1; i++)
        arr[i] = arr[i + 1];
    *n -= 1;
    arr = (int *)realloc(arr, sizeof(int) * (*n));
    return arr;
}

int *insert_handle(int *arr, int *n, int index, int item)
{
    if (index == 1)
        return insert(arr, n, 0, item);
    else if (index == 2)
        return insert(arr, n, (*n) / 2, item);
    else if (index == 3)
        return insert(arr, n, *n, item);
    else
        return insert(arr, n, index, item);
}

int *del_handle(int *arr, int *n, int index)
{
    if (index == 1)
        return del(arr, n, 0);
    else if (index == 2)
        return del(arr, n, (*n) / 2);
    else if (index == 3)
        return del(arr, n, *n);
    else
        return del(arr, n, index);
}

int Pos()
{
    int n;
    cout << "1.Beginning\n2.Middle\n3.End\nEnter the Position : ";
    cin >> n;
    return n;
}

int main()
{
    int len = 0, n, item, index;
    cout << "Enter the No. of Elements : ";
    cin >> len;
    if (len <= 0)
    {
        cout << "Warning!!! Invalid Index" << endl;
        exit(0);
    }
    int *arr = (int *)malloc(sizeof(int) * len);
    cout << "Enter the Elements of the Array :\n";
    for (int i = 0; i < len; i++)
        cin >> arr[i];
    do
    {
        cout << "1.Insert Element at a index\n2.Insert element at a Position\n";
        cout << "3.Delete Element at a index\n4.Delete element at a Position\n";
        cout << "5.Print Array\n0.Exit\nEnter your choice : ";
        cin >> n;
        switch (n)
        {
        case 1:
        {
            cout << "Enter the Element : ";
            cin >> item;
            cout << "Enter the Index : ";
            cin >> index;
            arr = insert(arr, &len, index, item);
            break;
        }
        case 2:
        {
            index = Pos();
            cout << "Enter the Element : ";
            cin >> item;
            arr = insert_handle(arr, &len, index, item);
            break;
        }
        case 3:
        {
            cout << "Enter the Index : ";
            cin >> index;
            arr = del(arr, &len, index);
            break;
        }
        case 4:
        {
            index = Pos();
            arr = del_handle(arr, &len, index);
            break;
        }
        case 5:
        {
            for (int i = 0; i < len; i++)
                cout << arr[i] << "\t";
            cout << "\n";
        }
        case 0:
            break;
        default:
            cout << "Unknown Option.";
        }
    } while (1);
    return 0;
}
