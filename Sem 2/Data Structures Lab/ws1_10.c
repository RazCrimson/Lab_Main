#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *string_replace(char *initial, char *replace, char *with) {
    char *result; 
    char *tmp;    
    char *insert;    
    int len_rep;  
    int len_with; 
    int len_front;
    int count;    

    len_rep = strlen(replace);
    len_with = strlen(with);
    if (len_rep == 0)
        return NULL;
    if (with == NULL)
        with = "";

    insert = initial;
    for (count = 0; tmp = strstr(insert, replace); ++count) {
        insert = tmp + len_rep;
    }

    tmp = result = malloc(strlen(initial) + (len_with - len_rep) * count + 1);

    if (!result)
        return NULL;

    while (count--) {
        insert = strstr(initial, replace);
        len_front = insert - initial;
        tmp = strncpy(tmp, initial, len_front) + len_front;
        tmp = strcpy(tmp, with) + len_with;
        initial += len_front + len_rep; 
    }
    strcpy(tmp, initial);
    return result;
}


int main()
{
    char str[80],s1[10],s2[10];
    printf("\nEnter the string:");
    scanf("%[^\n]s",str);
    printf("\nEnter the substring to be replaced:");
    getchar();
    scanf("%[^\n]s",s1);
    printf("\nEnter the substring to replace with:");
    getchar();
    scanf("%[^\n]s",s2);
    printf("\nReplaced String : %s",string_replace(str,s1,s2));
    return 0;
}