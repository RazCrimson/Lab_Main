#include <stdio.h>

int main()
{
    char ch;
    printf("\n\t\t ##### Tel-Number Calulation #####");
    printf("\nEnter the Character(Except Q,q)  : ");
    scanf("%c", ch);
    switch (ch)
    {
    case 'a':
    case 'b':
    case 'c':
    case 'A':
    case 'B':
    case 'C':
        printf("\nThe Number is 2.");
        break;
    case 'd':
    case 'e':
    case 'f':
    case 'D':
    case 'E':
    case 'F':
        printf("\nThe Number is 3.");
        break;
    case 'g':
    case 'h':
    case 'i':
    case 'G':
    case 'H':
    case 'I':
        printf("\nThe Number is 4.");
        break;
    case 'j':
    case 'k':
    case 'l':
    case 'J':
    case 'K':
    case 'L':
        printf("\nThe Number is 5.");
        break;
    case 'm':
    case 'n':
    case 'o':
    case 'M':
    case 'N':
    case 'O':
        printf("\nThe Number is 6.");
        break;
    case 'p':
    case 'r':
    case 's':
    case 'P':
    case 'R':
    case 'S':
        printf("\nThe Number is 7.");
        break;
    case 't':
    case 'u':
    case 'v':
    case 'T':
    case 'U':
    case 'V':
        printf("\nThe Number is 8.");
        break;
    case 'x':
    case 'y':
    case 'z':
    case 'X':
    case 'Y':
    case 'Z':
        printf("\nThe Number is 9.");
        break;
    default:
        printf("\n\nError!!! Invalid Number. ");
    }
    printf("\n");
    return 0;
}
