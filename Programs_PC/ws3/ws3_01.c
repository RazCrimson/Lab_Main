#include <stdio.h>

int main()
{
    unsigned short Choice, Input_Month, Month_Days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    printf("\n\t\t##### Days in a month #####");
    printf("\n\nEnter the Month to be displayed : ");
    scanf("%hu", &Input_Month);
    if (Input_Month > 0 && Input_Month < 13)
    {
        if (Input_Month == 2)
        {
            printf("Is the Year, a Leap Year(Enter 1 if so)  : ");
            scanf("%hu", &Choice);
            if (Choice == 1)
                Month_Days[1]++;
        }
        switch (Input_Month--)
        {
        case 1:
            printf("\n\nThere are %hu days in January. ", Month_Days[Input_Month]);
            break;
        case 2:
            printf("\n\nThere are %hu days in Feburary. ", Month_Days[Input_Month]);
            break;
        case 3:
            printf("\n\nThere are %hu days in March. ", Month_Days[Input_Month]);
            break;
        case 4:
            printf("\n\nThere are %hu days in April. ", Month_Days[Input_Month]);
            break;
        case 5:
            printf("\n\nThere are %hu days in May. ", Month_Days[Input_Month]);
            break;
        case 6:
            printf("\n\nThere are %hu days in June. ", Month_Days[Input_Month]);
            break;
        case 7:
            printf("\n\nThere are %hu days in July. ", Month_Days[Input_Month]);
            break;
        case 8:
            printf("\n\nThere are %hu days in August ", Month_Days[Input_Month]);
            break;
        case 9:
            printf("\n\nThere are %hu days in September. ", Month_Days[Input_Month]);
            break;
        case 10:
            printf("\n\nThere are %hu days in October ", Month_Days[Input_Month]);
            break;
        case 11:
            printf("\n\nThere are %hu days in November. ", Month_Days[Input_Month]);
            break;
        case 12:
            printf("\n\nThere are %hu days in December. ", Month_Days[Input_Month]);
            break;
        }
    }
    else
    {
        printf("\nERROR!!!");
        exit(9);
    }

    return 0;
}
