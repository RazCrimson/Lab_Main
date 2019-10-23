#include <stdio.h>

int main()
{
    char person1[100], person2[100];
    int score1, score2;
    printf("Enter the first person's name: ");
    scanf("%s", person1);
    printf("Enter the first person's score: ");
    scanf("%d", &score1);
    printf("Enter the second person's name: ");
    scanf("%s", person2);
    printf("Enter the second person's score: ");
    scanf("%d", &score2);
    if (score1 > score2)
    {
        printf("%s won by %d\n", person1, score1 - score2);
    }
    else if (score2 > score1)
    {
        printf("%s won by %d\n", person2, score2 - score1);
    }
    else
        printf("Its a tie\n");
    return 0;
}