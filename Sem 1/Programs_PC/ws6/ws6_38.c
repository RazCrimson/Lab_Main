#include <stdio.h>

int main()
{
    int a[100], b[100], c[200];
    int m, n, i = 0, j = 0, k = 0;
    printf("Enter the no. of elements in the ARRAY-1: ");
    scanf("%d", &m);
    printf("Enter the elements in the ARRAY-1:\n");
    for (i = 0; i < m; i++)
        scanf("%d", &a[i]);
    printf("Enter the number of elements in the ARRAY-2: ");
    scanf("%d", &n);
    printf("Enter the elements in the ARRAY-2:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &b[i]);
    i = 0;
    while (i < m && j < n)
    {
        if (a[i] < b[j])
        {
            c[k++] = a[i++];
        }
        else
        {
            c[k++] = b[j++];
        }
    }
    while (i < m)
    {
        c[k++] = a[i++];
    }
    while (j < n)
    {
        c[k++] = b[j++];
    }
    printf("The sorted array is:\n");
    for (i = 0; i < k; i++)
        printf("%d ", c[i]);
    printf("\n");
    return 0;
}