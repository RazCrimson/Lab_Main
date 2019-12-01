#include <stdio.h>
#include <math.h>

int main()
{
	float x,y,r,t,z;
	printf("\n\t\t ##### Polar Coordinates #####");
	printf("\n\nEnter the value of x :");
	scanf("%f",&x);
	printf("\nEnter the value of y :");
	scanf("%f",&y);
	r=pow(x*x+y*y,0.5);
	t=atan((y/x))*((180*7)/22);
	if((x<0&&y<0)||(x<0&&y>0))
		t+=180;
	else if(x>0&&y<0)
		t+=360;
	if(x<0&&y<0)
		printf("\nIt is in the III quadrant");
	else if(x>0&&y>0)
		printf("\nIt is in the I quadrant");
	else if(x>0&&y<0)
		printf("\nIt is in the IV quadrant");
	else if(x<0&&y>0)
		printf("\nIt is in the II quadrant");
	printf("\nThe Value of r is %f\nThe Value of Theta is %f\n",r,t);
	
	return 0;
}
