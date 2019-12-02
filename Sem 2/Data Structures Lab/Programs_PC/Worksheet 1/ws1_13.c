#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *word = (char *)malloc(sizeof(char) * 100);
    char delim = ' ', pass[100];
    printf("\nEnter the Input Word : ");
    scanf("%[^\n]s", word);
    word = realloc(word, sizeof(char) * (strlen(word) + 4));
    if (word != NULL)
    {
        int len = strlen(word);
        printf("Noun : %s\n", word);
        if (word[len - 1] == 'y')
        {
            strcpy(word + len - 1, "ies");
            len += 2;
            word[len] = '\0';
        }
        else if (word[len - 1] == 's')
        {
            strcpy(word + len, "es");
            len += 2;
            word[len] = '\0';
        }
        else if (strcmp(word + len - 2, "sh") == 0 || strcmp(word + len - 2, "ch") == 0)
        {
            strcpy(word + len, "es");
            len += 2;
            word[len] = '\0';
        }
        else
        {
            word[len] = 's';
            len++;
            word[len] = '\0';
        }
        printf("Plural : %s\n", word);
    }
    return 0;
}