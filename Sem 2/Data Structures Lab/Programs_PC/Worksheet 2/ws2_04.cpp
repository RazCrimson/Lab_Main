#include <iostream>

using namespace std;

int swap(int &, int &);
int swapArr(int *, int, int);
int copy(int *, int *, int);
int remBeg(int *, int, int *, int);
int remMid(int *, int, int *, int, int);
int remEnd(int *, int, int *, int);
int merge(int *, int, int *, int, int *, int);
int mergeSort(int *, int, int *, int, int *, int &);

int main()
{
    int choice, num1, num2, len, len1, len2, len3, i, sub_choice;
    char option;
    do
    {
        cout << "Available Options\n";
        cout << "1.Swap 2 numbers\n";
        cout << "2.Swap the contents of 2 elements in an array\n";
        cout << "3.Copy the contents of one array into another array\n";
        cout << "4.Remove the sub element from the array and copy into another\n";
        cout << "5.Merge 2 arrays\n";
        cout << "6.Merge 2 sorted arrays\n";
        cout << "Enter your choice:\n";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter the first number: \n";
            cin >> num1;
            cout << "Enter the second number: \n";
            cin >> num2;
            swap(num1, num2);
            cout << "The first number after swap is " << num1 << endl;
            cout << "The second number after swap is " << num2 << endl;
        }
        else if (choice == 2)
        {
            cout << "Enter the number of elements in the array: ";
            cin >> len;
            if (len <= 0)
            {
                cout << "Invalid array length\n";
                break;
            }
            int *arr = new int[len];
            cout << "Enter the elements of the array:\n";
            for (i = 0; i < len; i++)
                cin >> arr[i];
            cout << "Enter the positions to be swapped:\n";
            cin >> num1 >> num2;
            if (num1 < 1 || num2 < 1 || num1 > len - 1 || num2 > len - 1)
            {
                cout << "Enter valid positions\n";
                break;
            }
            swap(arr[num1 - 1], arr[num2 - 1]);
            cout << "The array after swap is\n";
            for (i = 0; i < len; i++)
                cout << arr[i] << "\t";
            cout << endl;
            delete[] arr;
        }
        else if (choice == 3)
        {
            cout << "Enter the number of elements of the array: ";
            cin >> len;
            if (len <= 0)
            {
                cout << "Invalid array length\n";
                break;
            }
            int *arr1 = new int[len];
            int *arr2 = new int[len];
            cout << "Enter the elements of the array:\n";
            for (i = 0; i < len; i++)
                cin >> arr1[i];
            copy(arr1, arr2, len);
            cout << "The elements of the copied array are:\n";
            for (i = 0; i < len; i++)
                cout << arr2[i] << "\t";
            cout << endl;
            delete[] arr1;
            delete[] arr2;
        }
        else if (choice == 4)
        {
            cout << "Enter the number of elements in the array: ";
            cin >> len;
            if (len <= 0)
            {
                cout << "Invalid array length\n";
                break;
            }
            int *arr1 = new int[len1];
            cout << "Enter the elements of the array\n";
            for (i = 0; i < len; i++)
                cin >> arr1[i];
            cout << "Available options\n";
            cout << "1.Sub elements from the beginning\n";
            cout << "2.Sub elements in the middle\n";
            cout << "3.Sub elements from the end\n";
            cout << "Enter your choice: ";
            if (sub_choice == 1)
            {
                cout << "Enter the position of the element to be removed from the beginning: ";
                cin >> num1;
                if (num1 < 1 || num1 > len1 - 1)
                {
                    cout << "Enter valid position\n";
                    break;
                }
                len2 = num1;
                int *arr2 = new int[len2];
                remBeg(arr1, len1, arr2, len2);
                cout << "The elements of the array are after removing are:\n";
                for (i = 0; i < len1; i++)
                    cout << arr1[i] << "\t";
                cout << endl;
                cout << "The elements of the sub array array are:\n";
                for (i = 0; i < len2; i++)
                    cout << arr2[i] << "\t";
                cout << endl;
                delete[] arr1;
                delete[] arr2;
            }
            else if (sub_choice == 2)
            {
                cout << "Enter the range of position of the elements to be removed in the middle\n:";
                cin >> num1 >> num2;
                if (num1 < 1 || num2 < 1 || num1 > len - 1 || num2 > len - 1 || num1 > num2)
                {
                    cout << "Enter valid position\n";
                    break;
                }
                len2 = num2 - num1 + 1;
                int *arr2 = new int[len2];
                remMid(arr1, len1, arr2, num1, num2);
                cout << "The elements of the array are after removing are:\n";
                for (i = 0; i < len1; i++)
                    cout << arr1[i] << "\t";
                cout << endl;
                cout << "The elements of the sub array array are:\n";
                for (i = 0; i < len2; i++)
                    cout << arr2[i] << "\t";
                cout << endl;
                delete[] arr1;
                delete[] arr2;
            }
            else if (sub_choice == 3)
            {
                cout << "Enter the position of the element to be removed from the end: ";
                cin >> num1;
                if (num1 < 1 || num1 > len - 1)
                {
                    cout << "Enter valid position\n";
                    break;
                }
                len2 = num1;
                int *arr2 = new int[len2];
                remEnd(arr1, len1, arr2, len2);
                cout << "The elements of the array are after removing are:\n";
                for (i = 0; i < len1; i++)
                    cout << arr1[i] << "\t";
                cout << endl;
                cout << "The elements of the sub array array are:\n";
                for (i = 0; i < len2; i++)
                    cout << arr2[i] << "\t";
                cout << endl;
                delete[] arr1;
                delete[] arr2;
            }
        }
        else if (choice == 5)
        {
            cout << "Enter the number of elements in the first array: ";
            cin >> len1;
            if (len1 <= 0)
            {
                cout << "Invalid array length\n";
                break;
            }
            int *arr1 = new int[len1];
            cout << "Enter the elements of the first array:\n";
            for (i = 0; i < len1; i++)
                cin >> arr1[i];
            cout << "Enter the number of elements in the second array: ";
            cin >> len2;
            if (len2 <= 0)
            {
                cout << "Invalid array length\n";
                break;
            }
            int *arr2 = new int[len2];
            cout << "Enter the elements of the second array:\n";
            for (i = 0; i < len2; i++)
                cin >> arr2[i];
            len3 = len1 + len2;
            int *arr3 = new int[len3];
            merge(arr1, len1, arr2, len2, arr3, len3);
            cout << "The elements of the merged array are:\n";
            for (i = 0; i < len3; i++)
                cout << arr3[i] << "\t";
            cout << endl;
            delete[] arr1;
            delete[] arr2;
            delete[] arr3;
        }
        else if (choice == 6)
        {
            cout << "Enter the number of elements in the first array: ";
            cin >> len1;
            if (len1 <= 0)
            {
                cout << "Invalid array length\n";
                break;
            }
            int *arr1 = new int[len1];
            cout << "Enter the elements of the first sorted array:\n";
            for (i = 0; i < len1; i++)
                cin >> arr1[i];
            cout << "Enter the number of elements in the second array: ";
            cin >> len2;
            if (len2 <= 0)
            {
                cout << "Invalid array length\n";
                break;
            }
            int *arr2 = new int[len2];
            cout << "Enter the elements of the second sorted array:\n";
            for (i = 0; i < len2; i++)
                cin >> arr2[i];
            len3 = len1 + len2;
            int *arr3 = new int[len3];
            merge(arr1, len1, arr2, len2, arr3, len3);
            cout << "The elements of the merged array are:\n";
            for (i = 0; i < len3; i++)
                cout << arr3[i] << "\t";
            cout << endl;
            delete[] arr1;
            delete[] arr2;
            delete[] arr3;
        }
        else
        {
            cout << "Invalid choice";
            break;
        }

        cout << "Do you want to continue? (y/n): ";
        cin >> option;
    } while (option == 'y' || option == 'Y');
}

int swap(int &num1, int &num2)
{
    num1 = num1 ^ num2;
    num2 = num1 ^ num2;
    num1 = num1 ^ num2;
    return 0;
}

int copy(int *arr1, int *arr2, int len)
{
    for (int i = 0; i < len; i++)
        arr2[i] == arr1[i];
    return 0;
}

int merge(int *arr1, int len1, int *arr2, int len2, int *arr3, int len3)
{
    int i;
    for (i = 0; i < len1; i++)
        arr3[i] = arr1[i];
    for (i = 0; i < len2; i++)
        arr3[i + len1] = arr2[i];
    return 0;
}

int mergeSort(int *arr1, int len1, int *arr2, int len2, int *arr3, int &len3)
{
    int i = 0, j = 0, k = 0;
    while (i < len1 && j < len2)
    {
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else if (arr1[i > arr2[j]])
            arr3[k++] = arr2[j++];
        else
        {
            arr3[k++] = arr1[i++];
            j++;
        }
    }
    while (i < len1)
        arr3[k++] = arr1[i++];
    while (j < len2)
        arr3[k++] = arr2[j++];
    len3 = k;
    arr3 = (int *)realloc(arr3, len3 * sizeof(int));
    return 0;
}

int remBeg(int *arr1, int len1, int *arr2, int len2)
{
    int i;
    for (i = 0; i < len2; i++)
        arr2[i] = arr1[i];
    for (i = len2; i < len1; i++)
        arr1[i - len2] = arr1[i];
    len1 -= len2;
    arr1 = (int *)realloc(arr1, len1 * sizeof(int));
}

int remMid(int *arr1, int len1, int *arr2, int pos1, int pos2)
{
    int i, len2 = pos2 - pos1 + 1;
    for (i = 0; i < len2; i++)
        arr2[i] = arr1[i + pos1 - 1];
    for (i = pos2; i < len1; i++)
        arr1[i - len2] = arr1[i];
    len1 -= len2;
    arr1 = (int *)realloc(arr1, len1 * sizeof(int));
}

int remEnd(int *arr1, int len1, int *arr2, int len2)
{
    int i;
    for (i = len2 - 1; i < len1; i++)
        arr2[i] = arr1[i + len2 - 1];
    len1 -= len2;
    arr1 = (int *)realloc(arr1, len1 * sizeof(int));
}