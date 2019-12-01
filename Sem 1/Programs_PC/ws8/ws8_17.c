#include <stdio.h>

int main()
{
    char **s;
    char foo[] = "Hello World";
    printf("hi\n");
    s = &foo;
    printf("hi\n");
    printf("s is %s\n", s);
    printf("\nhi\n");
    char *f1;
    f1 = malloc(10);
    strcpy(f1, foo);
    s[0] = f1;
    printf("s[0] is %s\n", s[0]);
    return 0;
}
