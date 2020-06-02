#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *encode(char *str, int n)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
        str[i] += n;
    printf("The encoded line of text is %s\n", str);
    return str;
}

char *decode(char *str, int n)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
        str[i] -= n;
    printf("The decode line of text is %s\n", str);
    return str;
}

int main()
{
    int n, len, ch = 0;
    char *res, str[100] = {0};
    printf("Enter the line of text:\n");
    scanf("%[^\n]s", str);
    printf("Enter the integer: ");
    scanf("%d", &n);
    printf("1.Encode\n2.Decode\nEnter your choice :");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        res = encode(str, n);
        break;

    case 2:
        res = decode(str, n);
        break;
    default:
        printf("Not a valid choice!");
        exit(0);
    }
    return 0;
}