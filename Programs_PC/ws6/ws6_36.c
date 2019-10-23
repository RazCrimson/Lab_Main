#include <stdio.h>

int main()
{
    int j, i, k, n, a[5] = {0}, spoilt = 0;
    printf("Enter the no. of voters: ");
    scanf("%d", &n);
    printf("Enter your choice from 1 to 5:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &k);
        if (k < 1 || k > 5)
        {
            printf("Spoilt Ballot\n");
            spoilt++;
        }
        else
        {
            for (j = 1; j <= 5; j++)
            {
                if (k == j)
                    a[j - 1]++;
            }
        }
    }
    printf("The result is:\nCandidates:\n");
    for (i = 1; i < 6; i++)
        printf("%d\t", i);
    printf("\n");
    for (i = 0; i < 5; i++)
        printf("%d\t", a[i]);
    printf("\n");
    printf("The number of spoilt ballots are %d\n", spoilt);
    return 0;
}