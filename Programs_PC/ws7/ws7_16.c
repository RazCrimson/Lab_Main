#include <stdio.h>
#include <string.h>

int main()
{
        char shortened[][5] = {"ur","imo", "lol", "cul", "asap", "cu", "lmk", "hand"};
        char expanded[][20] = {"Your","In my opinion", "Laugh out loud", "See you later", "As soon as possible", "See you", "Let me know", "Have a nice day"};
        printf("Enter the SMS abbreviation:\n");
        char s1[5];
        scanf("%[^\n]s", s1);
        int i;
        int flg = 0;
        for(i=0;i<8;i++)
        {
                if(!strcmp(shortened[i], s1))
                {
                        flg = 1;
                        printf("The equivalent English phrase is: %s\n", expanded[i]);
                }
        }
        if(!flg)
                printf("SMS Abbreviation not found\n");
        return 0;
}





