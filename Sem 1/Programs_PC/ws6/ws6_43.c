#include <stdio.h>
int main()
{
        int ar[20];
        printf("\n Enter the scores for ten frames(terminated by an input greater than 10):");
        int i, n;
        for (i = 0;; i++)
        {
                scanf("%d", &ar[i]);
                if (ar[i] > 10)
                {
                        n = i - 1;
                        break;
                }
        }
        int frame = 1, score = 0;
        printf("\nFrame\tscore");
        printf("\n-------------");
        for (i = 0; i < n; i++, frame++)
        {
                int sum = 0;
                if (ar[i] == 10)
                {
                        sum = ar[i] + ar[i + 1] + ar[i + 2];
                        score += sum;
                        printf("\n%d\t%d", frame, score);
                }
                else if ((ar[i] + ar[i + 1]) == 10)
                {
                        sum = ar[i] + ar[i + 1] + ar[i + 2];
                        score += sum;
                        printf("\n%d\t%d", frame, score);
                        i++;
                }
                else if ((ar[i] + ar[i + 1]) < 10)
                {
                        sum = ar[i] + ar[i + 1];
                        score += sum;
                        printf("\n%d\t%d", frame, score);
                        i++;
                }
        }
        printf("\n");
}
