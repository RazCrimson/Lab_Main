#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_plural(char *word)
{
    if (word != NULL)
    {
        int len = strlen(word);
        printf("Noun : %s\n", word);

        if (word[len - 1] == 'y')
        {
            word[len - 1] = 'i';
            printf("Plural : %ses\n", word);
        }
        else if (word[len - 1] == 's' || (word[len - 2] == 'c' && word[len - 1] == 'h') || (word[len - 2] == 's' && word[len - 1] == 'h'))
            printf("Plural : %ses\n", word);
        else
            printf("Plural : %ss\n", word);
    }
}

int main()
{
    char *arr = (char *)malloc(sizeof(char) * 1000);
    char delim = ' ', pass[100];
    printf("\nEnter the Input String : ");
    scanf("%[^\n]s", arr);
    arr = realloc(arr, sizeof(char) * (strlen(arr) + 1));
    printf("%s\n", arr);
    char *word = strtok(arr, &delim);
    while (word != NULL)
    {
        print_plural(word);
        word = strtok(NULL, &delim);
    }
    return 0;
}