#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *arr = (char *)malloc(sizeof(char) * 150);
    char delim = ' ', *cpy = "";
    printf("\nEnter the Input String : ");
    scanf("%[^\n]s", arr);
    arr = realloc(arr, sizeof(char) * (strlen(arr) + 1));
    printf("Name is %s\n", arr);
    char *word = strtok(arr, &delim);
    printf("Initials : ",*word);
    do
    {
        printf("%c ",*word);
        word = strtok(NULL, &delim);
        if(word == NULL)
            break;
        cpy = word;
    }while(1);
    printf("\b%s",cpy + 1);
    return 0;
}