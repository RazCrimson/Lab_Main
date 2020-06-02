#include <stdio.h>
#include <string.h>

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(char *arr, int n)
{
    int i, j, flg = 0;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                flg = 1;
            }
        }
        if (flg == 0)
            break;
    }
}

int main()
{
    char arr[1000];
    int len = 0;
    printf("\nEnter the String : ");
    scanf("%s", arr);
    len = strlen(arr);
    bubbleSort(arr, len);
}