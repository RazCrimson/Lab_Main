#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *arr = (char *)calloc(1000, sizeof(char));
    int len = 0;
    printf("\nEnter the Input String : ");
    scanf("%[^\n]s", arr);
    arr = realloc(arr, sizeof(char) * (strlen(arr) + 1));
    len = strlen(arr);
    for (int i = 0; i < len - 1; i++)
        if (arr[i] == ' ' && arr[i + 1] == ' ')
        {
            for (int j = i + 1; j < len; j++)
            {
                char temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
            i--;
            len--;
            arr[len - 1] == '\0';
        }
    printf("\n%s", arr);
    for (int i = 0; i < len - 1; i++)
        if (arr[i] == ' ')
        {
            for (int j = i; j < len; j++)
            {
                char temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
            i--;
            len--;
            arr[len - 1] == '\0';
        }
    printf("\n%s", arr);
    return 0;
}