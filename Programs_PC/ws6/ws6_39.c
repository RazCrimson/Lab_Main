#include <stdio.h>
#include <string.h>

void main()
{
    int i, n;
    char s1[10], s2[10], s3[10];
    printf("Enter the string: ");
    scanf("%s", s1);
    n = strlen(s1);
    printf("The length is %d\n", n);
    strcpy(s2, s1);
    printf("The copied string is %s\n", s2);
    for (i = 0; i < n / 2; i++)
    {
        s1[i] = s1[i] ^ s1[n - i - 1];
        s1[n - i - 1] = s1[i] ^ s1[n - i - 1];
        s1[i] = s1[i] ^ s1[n - i - 1];
    }
    printf("The reversed string is %s\n", s1);
    printf("Enter the new string: ");
    scanf("%s", s3);
    n = strcmp(s2, s3);
    if (n < 0)
        printf("First string is alphabetically first\n");
    else if (n > 0)
        printf("Second string is alphabetically first\n");
    else
        printf("Both strings are same\n");
    return 0;
}