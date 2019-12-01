#include <stdio.h>

int main()
{
	int r,h,w,ch=0;
	float res;
	printf("\t\t ##### Area Calculation #####");
	printf("\nEnter 1 for Sphere\nEnter 2 for Cylinder\nEnter 3 for Cone\nEnter 4 for Pyramid\nEnter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		printf("\n\nEnter the Radius : ");
		scanf("%d",&r);
		res=(4/3)*3.1428*r*r*r;
		printf("\nArea of Sphere %f",res);
		break;

		case 2:
		printf("\nEnter the Radius : ");
		scanf("%d",&r);
		printf("\nEnter the Height : ");
		scanf("%d",&h);
		res=3.1428*r*r*h;
		printf("\nArea of Cylinder: %f",res);
		break;

		case 3:
		print("\nEnter the Radius : ");
		scanf("%d",&r);
		printf("\nEnter the Height : ");
		scanf("%d",&h);
		res=0.3333*3.1428*r*r*h;
		printf("\nArea of Cone: %f",res);
		break;

		case 4:
		print("\nEnter the Width : ");
		scanf("%d",&w);
		printf("\nEnter the Height : ");
		scanf("%d",&h);
		print("\nEnter the Length : ");
		scanf("%d",&r);
		res=0.3333*r*w*h;
		printf("\nArea of Pyramid : %f",res);
		break;

		case 0:
		printf("n\nError!!!\n ");
	}
	printf("\n");

	return 0;
}





