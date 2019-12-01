#include <stdio.h>
#include <string.h>

void numpalindrome(int num)
{
    char string[20];
    int i = 0, len;
    sprintf(string, "%d", num);
    len = strlen(string);
    for (i = 0; i < (len + 1); i++)
        if (string[i] != string[len - i - 1])
            break;
    if (i == len + 1)
        printf("\n%d is a palindrome!\n", num);
    else
        printf("\n%d is not a palindrome!\n", num);
}

void Isvowel(char *arr)
{
    int count = 0, len = 0;
    len = strlen(arr);
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u' || arr[i] == 'A' || arr[i] == 'E' || arr[i] == 'I' || arr[i] == 'O' || arr[i] == 'U')
        {
            count++;
        }
    }
    printf("\nThe Number of Vowels in the string is : %d", count);
}

void q1()
{
    int num = 0;
    printf("\nEnter a Number : ");
    scanf("%d", &num);
    numpalindrome(num);
}

void q2()
{
    char *arr = (char *)calloc(1000, sizeof(char));
    printf("\nEnter a String : ");
    getchar();
    scanf("%[^\n]s", arr);
    arr=(char*)realloc(arr,sizeof(char)*(strlen(arr)+1));
    Isvowel(arr);
}

int main()
{
    char ch;
    printf("\nEnter a for First sub-heading.\
    \nEnter b for Second sub-heading.\nEnter your choice : ");
    scanf("%c", &ch);
    if (ch == 'a')
        q1();
    else if (ch == 'b')
        q2();
    return 0;
}
