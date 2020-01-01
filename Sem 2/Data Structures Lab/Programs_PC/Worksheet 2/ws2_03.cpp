#include <iostream>
using namespace std;

int main()
{
    int len1, len2, len3, len4, len5, flag = 0, i, j, k;
    cout << "Enter the number of elements in first array: ";
    cin >> len1;
    int *a1 = new int[len1];
    cout << "Enter the elements of first array:" << endl;
    for (i = 0; i < len1; i++)
        cin >> a1[i];
    cout << "Enter the number of elements in second array: ";
    cin >> len2;
    int *a2 = new int[len2];
    cout << "Enter the elements of second array:" << endl;
    for (i = 0; i < len2; i++)
        cin >> a2[i];
    
    if (len1 < len2)
        len3 = len2;
    else
        len3 = len1;

    int *a3 = new int[len3];
    cout << "The third array is:" << endl;
    for (i = 0; i < len3; i++)
    {
        a3[i] = a1[i] + a2[i];
        cout << a3[i] << "\t";
    }
    cout << endl;

    int *a4 = new int[len1];
    cout << "The fourth array is:" << endl;
    for (i = 0; i < len1; i++)
    {
        a4[i] = a1[i];
        cout << a4[i] << "\t";
    }
    cout << endl;
    
    for (i = 0; i < len3 / 2; i++)
    {
        a3[i] = a3[i] ^ a3[len3 - i - 1];
        a3[len3 - i - 1] = a3[i] ^ a3[len3 - i - 1];
        a3[i] = a3[i] ^ a3[len3 - i - 1];
    }
    cout << "The third array after reversing is:" << endl;
    for (i = 0; i < len3; i++)
        cout << a3[i] << "\t";
    cout << endl;

    cout << "The common elements in first and second array are:" << endl;
    for (i = 0; i < len1; i++)
    {
        for (j = 0; j < len2; j++)
        {
            if (a1[i] == a2[j])
                cout << a1[i] << "\t";
        }
    }
    cout << endl;
    
    for (i = 0; i < len1; i++)
    {
        for (j = 0; j < len2; j++)
        {
            if (a1[i] == a2[j])
            {
                for (k = j; k < len2 - 1; k++)
                    a2[k] = a2[k + 1];
                j--;
                len2--;
            }
        }
    }
    cout << "The second array after removing common elements is:" << endl;
    for (i = 0; i < len2; i++)
        cout << a2[i] << "\t";
    cout << endl;
    
    len5 = len1 + len2;
    int *a5 = new int[len5];
    for (i = 0; i < len1; i++)
        a5[i] = a1[i];
    for (i = 0; i < len2; i++)
        a5[i + len1] = a2[i];
    for (i = 0; i < len5 - 1; i++)
    {
        for (j = i + 1; j < len5; j++)
        {
            if (a5[i] == a5[j])
            {
                for (k = j; k < len5 - 1; k++)
                    a2[k] = a2[k + 1];
                j--;
                len5--;
            }
        }
    }
    cout << "The fifth array is:" << endl;
    for (i = 0; i < len5; i++)
        cout << a5[i] << "\t";
    cout << endl;
    for (i = 0; i < len1; i++)
    {
        for (j = 0; j < len3; j++)
        {
            if (a1[i] == a3[j])
                flag = 1;
        }
        if (flag == 0)
        {
            cout << "First array is not a subset of third array" << endl;
            break;
        }
    }
    if (flag)
        cout << "First array is a subset of third array" << endl;
}