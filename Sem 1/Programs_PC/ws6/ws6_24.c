#include <stdio.h>
#include <string.h>

int main()
{
    char a[100];
    int score = 0, i, len;
    printf("Enter the word: ");
    scanf("%s", a);
    len = strlen(a);
    for (i = 0; i < len; i++)
    {
        switch (a[i])
        {
        case 'Q':
        case 'Z':
            score += 10;
            break;

        case 'J':
        case 'X':
            score += 8;
            break;

        case 'F':
        case 'H':
        case 'V':
        case 'W':
        case 'Y':
            score += 4;
            break;

        case 'B':
        case 'C':
        case 'M':
        case 'P':
            score += 3;
            break;

        case 'D':
        case 'G':
            score += 2;
            break;

        case 'A':
        case 'E':
        case 'I':
        case 'L':
        case 'N':
        case 'U':
        case 'O':
        case 'R':
        case 'S':
        case 'T':
            score += 1;
            break;
        }
    }

    printf("The score is %d\n", score);
    return 0;
}