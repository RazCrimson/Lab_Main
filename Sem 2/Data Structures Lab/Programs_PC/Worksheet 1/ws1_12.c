#include <stdio.h>

int main()
{
    int i, len = -1;
    char arr[20], str[20];
    printf("Enter the first string: ");
    scanf("%s", arr);
    printf("Enter the second string: ");
    scanf("%s", str);
    for (i = 0; arr[i] != '\0' && str[i] != '\0'; i++)
    {
        if (arr[i] == str[i])
            len = i;
    }
    arr[len + 1] = '\0';
    if (len == -1)
        printf("There are no common prefixes\n");
    else
        printf("The largest common prefix is %s\n", arr);
    return 0;
}