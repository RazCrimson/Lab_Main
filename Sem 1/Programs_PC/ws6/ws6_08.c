#include <stdio.h>
#include <stdlib.h>

int bubbleSort(int *arr, int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
}

int main()
{
	int n = 0, k = 0, count = 1;
	printf("\nEnter the Size of Array : ");
	scanf("%d", &n);
	if (n <= 0)
	{
		printf("\nERROR!! Array index cant be negative.");
		exit(-1);
	}
	printf("\nEnter the Number k : ");
	scanf("%d", &k);
	printf("Enter the Elements of the array : ");
	int *arr = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	bubbleSort(arr, n);
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == arr[i + 1])
			count++;
		else if (arr[i] != arr[i + 1])
		{
			if (count >= n / k)
				printf("\n%d", arr[i - 1]);
			count = 1;
		}
		printf("\ni=%d", i);
	}
	return 0;
}