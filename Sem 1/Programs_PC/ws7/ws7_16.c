#include <stdio.h>
#include <string.h>

int main()
{
    char shortened[][5] = {"rip", "ur", "imo", "lol", "cul", "asap", "cu", "lmk", "hand"};
    char expanded[][30] = {"Rest In Peace", "Your", "In my opinion", "Laugh out loud", "See you later", "As soon as possible", "See you", "Let me know", "Have a nice day"};
    printf("Enter the SMS abbreviation:\n");
    char input[5];
    scanf("%[^\n]s", input);
    int i, flg = 0;
    for (i = 0; i < 9; i++)
    {
        if (strcmp(shortened[i], input) == 0)
        {
            flg = 1;
            printf("The equivalent English phrase is: %s\n", expanded[i]);
        }
    }
    if (!flg)
        printf("SMS Abbreviation not found\n");
    return 0;
}
