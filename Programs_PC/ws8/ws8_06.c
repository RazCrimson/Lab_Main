#include <stdio.h>
#include <string.h>
#include <ctype.h>
//check required
int swap(char *x, char *y)
{
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}

int main()
{
    char arr[1000];
    int i = 0, len = 0;
    printf("\nWorksheet 8: Program 6");
    printf("\nEnter a string within 999 characters  : ");
    scanf("%s", arr);
    len = strlen(arr);
    for (int i = 0; i < (len / 2); i++)
        swap(&arr[i], &arr[len - i]);
    printf("str:%s\n", arr);
    return 0;
}
