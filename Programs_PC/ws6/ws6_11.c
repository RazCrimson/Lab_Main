#include <stdio.h>
#include <string.h>

int main()
{
    char a[100];
    int i, j, n;
    printf("Enter the sentence: ");
    scanf("%[^\n]s", a);
    n = strlen(a);
    for (i = 0; i < n; i++)
    {
        if ((a[i] == 't' || a[i] == 'T') && (a[i + 1] == 'h' || a[i + 1] == 'H') && (a[i + 2] == 'e' || a[i + 2] == 'E'))
        {
            for (j = i; j < n - 1; j++)
            {
                a[j] = a[j + 3];
            }
            n = n - 3;
            i = i - 3;
        }
        if ((a[i] == 'a' || a[i] == 'A') && (a[i + 1] == 'n' || a[i + 1] == 'N'))
        {
            for (j = i; j < n - 1; j++)
            {
                a[j] = a[j + 2];
            }
            n = n - 2;
            i = i - 2;
        }
        if (a[i] == 'a' || a[i] == 'A')
        {
            for (j = i; j < n - 1; j++)
            {
                a[j] = a[j + 1];
            }
            n = n - 1;
            i = i - 1;
        }
    }
    printf("%s\n", a);
    return 0;
}