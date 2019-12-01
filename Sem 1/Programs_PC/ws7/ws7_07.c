#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char str[30], win[30] = "None";
	int curr, winn = 0;
	while (1)
	{
		printf("\n\nEnter the Name : ");
		fgets(str, 30, stdin);
		printf("\nEnter the Score : ");
		scanf("%d", &curr);
		getchar();
		if (curr > winn)
		{
			winn = curr;
			strcpy(win, str);
		}
		printf("\nMore Players? -1 to stop, other to continue : ");
		scanf("%d", &curr);
		getchar();
		if (curr == -1)
			break;
	}
	printf("\nThe Winner is %s \nScore : %d", win, winn);
	printf("\n");
	return 0;
}
