#include <stdio.h>

int main()
{
	int i;
	char name[] = "Yes", ans[100];
	printf("Answer Yes!\n");
	scanf("%[^\n]s", ans);
	for (i = 0; i < 8; i++)
	{
		if (name[i] != ans[i])
			break;
	}
	if (i == 8)
		printf("Good\n");
	else
		printf("Wrong\n");
	return 0;
}