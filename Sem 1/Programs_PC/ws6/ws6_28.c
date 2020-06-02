#include <stdio.h>

int main()
{
    int score[11];
    int k, max_sum = 0, count = 0;
    printf("\nEnter the scores of all the 11 batsmen.\n");
    for (int i = 0; i < 11; i++)
    {
        printf("%d.  ", i + 1);
        scanf("%d", &score[i]);
        printf("\n");
    }
    int temp[11];
    for (int i = 0; i < 11; i++)
    {
        temp[i] = score[i];
    }
    for (int i = 0; i < 11; i++)
    {
        int big, tmp, pos;
        big = temp[i];
        pos = i;
        for (int j = i; j < 11; j++)
        {
            if (temp[j] > big)
            {
                big = temp[j];
                pos = j;
            }
        }
        tmp = temp[i];
        temp[i] = temp[pos];
        temp[pos] = tmp;
    }
    printf("Enter the no.of elements in the subset.\n");
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        max_sum += temp[i];
    }
    count = 1;
    for (int i = k; i < 11; i++)
    {
        if (temp[i] == temp[k - 1])
        {
            count++;
        }
        else
            break;
    }
    printf("\nThe total number of possible subsets is : %d\n", count);
    return 0;
}
