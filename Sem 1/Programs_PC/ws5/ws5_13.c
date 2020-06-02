#include <stdio.h>

int main()
{
    int x;
    short i, j;
    printf("\nENnter the no : ");
    scanf("%d", &x);
    printf("Enter the ith and jth bits from the right :");
    scanf("%d%d", &i, &j);
    printf("\nTHe Binary representation : ");
    for (int i = 31; i >= 0; i--)
        printf("%d", (a >> i) & 1);
    if(((x>>i-1)&1)==((x>>j-1)&1))
        break;
    else
    {
        x = x ^ (1 << i - 1);
        x = x ^ (1 << j - 1);
    }
    printf("\nTHe Binary representation : ");
    for(int i=31;i>=0;i--)
		printf("%d",(a>>i)&1);

}