#include <stdio.h>

int main()
{
    int i = 10;
    char c = 'a';
    double d = 12.34;
    int *pi = &i;
    char *pc = &c;
    double *pd = &d;
    printf("Variable Name\t\tType\tMemory Size\tValue Stored\n");
    printf("i\t\tint\t\t%ld\t\t%d\n", sizeof(int), i);
    printf("c\t\tchar\t\t%ld\t\t%c\n", sizeof(char), c);
    printf("d\t\tdouble\t\t%ld\t\t%0.5lf\n", sizeof(double), d);
    printf("pi\t\tint*\t\t%ld\t\t%x\n", sizeof(int *), pi);
}
