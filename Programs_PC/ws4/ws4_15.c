#include <stdio.h>
#include <stdlib.h>

int main()
{
	float Eng, Mat, Phy, Val;
	int n, i = 1;
	Eng = Mat = Phy = 0;
	printf("\nInput number of students : ");
	scanf("%d", &n);
	if (n <= 0)
	{
		printf("\nERROR!!!");
		exit(-1);
	}
	while (i <= n)
	{
		printf("\nEnglish score of student %d ", i);
		scanf("%f", &Val);
		Eng += Val / n;
		printf("\nMath score of student %d ", i);
		scanf("%f", &Val);
		Mat += Val / n;
		printf("\nPhysics score of student %d ", i);
		scanf("%f", &Val);
		Phy += Val / n;
		i++;
	}
	printf("\nMean of english = %.2f\nMean of math    = %.2f\nMean of physics = %.2f\n", Eng, Mat, Phy);
	return 0;
}