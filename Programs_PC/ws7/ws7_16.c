#include <stdio.h>
#include <string.h>

int main()
{
        char code[][5] = {"ur","imo", "lol", "cul", "asap", "cu", "lmk", "hand"};
        char english[][20] = {"Your","In my opinion", "Laugh out loud", "See you later", "As soon as possible", "See you", "Let me know", "Have a nice day"};
        printf("Enter SMS abbreviation\n");
        char s1[5];
        scanf("%[^\n]s", s1);
        int i;
        int flg = 0;
        for(i=0;i<8;i++)
        {
                if(!strcmp(code[i], s1))
                {
                        flg = 1;
                        printf("The equivalent English phrase is: %s\n", english[i]);
                }
        }
        if(!flg)
                printf("SMS Abbreviation not found\n");
        return 0;
}






