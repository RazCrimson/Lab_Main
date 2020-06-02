#include <stdio.h>
#include <string.h>

int main()
{
    char arr[1000];
    printf("\nWhat is 1 + 1 in words : ");
    scanf("%s", arr);
    if (strcmp(arr, "one") == 0)
        printf("\nGood");
    else
        printf("\nBad");
    print("\n");
    return 0;
}