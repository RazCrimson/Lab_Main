#include <stdio.h>
#include <ctype.h>

int main()
{
    int i = 0;
    char str[100];
    char ch[][10] = {"-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    printf("Enter the text: ");
    scanf("%[^\n]s", str);
    while (str[i] != '\0')
    {
        if (isdigit(str[i]))
            printf("%s ", ch[str[i] - 48]);
        else if (isalpha(str[i]))
        {
            str[i] = toupper(str[i]);
            printf("%s ", ch[str[i] - 55]);
        }
        else if (str[i] == '.')
            printf(".-.-.- ");
        else if (str[i] == ',')
            printf("--..-- ");
        else if (str[i] == '?')
            printf("..--.. ");
        else if (str[i] == ' ')
            printf("\n");
        else
            printf(" ");
        i++;
    }
    printf("\n");
    return 0;
}