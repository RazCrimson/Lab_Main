#include <iostream>

using namespace std;

int main()
{
    int x, c_p = 0, c_n = 0, c_o = 0, c_e = 0, y, s_i = 0, c_g = 0, num, len, i, total = 0, j, k;
    float avg;

    cout << "Enter the number of elements: ";
    cin >> len;
    int *ar = new int[len];
    cout << "Enter the elements of the array:\n";
    for (i = 0; i < len; i++)
    {
        cin >> ar[i];
        total += ar[i];
    }
    avg = (float)total / len;
    cout << "The total is: " << total << "\n";
    cout << "The average is: " << avg << "\n";
    
    cout << "Enter the number: ";
    cin >> num;
    for (i = 0; i < len; i++)
    {
        if (ar[i] >= num)
            c_g++;
    }
    cout << c_g << " numbers are greater than " << num << "\n";

    cout << "Enter the integer x: ";
    cin >> x;
    for (i = 0; i < len; i++)
    {
        if (ar[i] == x)
        {
            cout << "Number found" << endl;
            i = 0;
            break;
        }
    }
    if (i)
        cout << "Number not found" << endl;

    for (i = 0; i < len; i++)
    {
        if (ar[i] > 0)
            c_p++;
        else if (ar[i] < 0)
            c_n++;
        if (ar[i] % 2 == 0)
            c_e++;
        else
            c_o++;
    }
    cout << "The number of positive numbers in the list are: " << c_p << endl;
    cout << "The number of negative numbers in the list are: " << c_n << endl;
    
    int *oar = new int[c_o];
    int *ear = new int[c_e];
    j = 0;
    k = 0;
    for (i = 0; i < len; i++)
    {
        if (ar[i] % 2 == 0)
            ear[j++] = ar[i];
        else
            oar[k++] = ar[i];
    }
    cout << "The number of odd numbers are: " << c_o << "and they are" << endl;
    for (i = 0; i < c_o; i++)
        cout << oar[i] << "\t";
    cout << endl;
    cout << "The number of even numbers are: " << c_e << "and they are" << endl;
    for (i = 0; i < c_e; i++)
        cout << ear[i] << "\t";
    cout << endl;
    
    cout << "Enter the number to be replaced: ";
    cin >> y;
    for (i = 0; i < len; i++)
    {
        if (i % 2 == 0)
            ar[i] = y;
    }
    cout << "The altered array is:" << endl;
    for (i = 0; i < len; i++)
        cout << ar[i] << "\t";
    cout << endl;
    
    cout << "Enter the integer to be searched: ";
    cin >> y;
    for (i = 0; i < len; i++)
    {
        if (ar[i] == y)
            s_i += i;
    }
    if (s_i == 0)
        cout << "Integer not found" << endl;
    else
        cout << "The sum of indices where this integer occurs is: " << s_i << endl;
}