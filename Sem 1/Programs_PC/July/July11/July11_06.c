#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,d,m,n;
	float x1,x2,s1,s2,s;
	printf("\n\t\t\t ##### Solving Linear Equationsn #####");
    printf("\nThe general form of the quation is ax + by + c = 0 ");
	printf("\n\nEnter the value of a of the first equation : ");
	scanf("%d",&a);
	printf("\nEnter the value of b of the first equation : ");
	scanf("%d",&b);
	printf("\nEnter the value of c of the first equation : ");
	scanf("%d",&m);
    m=-m;
	printf("\nEnter the value of a of the second equation : ");
	scanf("%d",&c);
	printf("\nEnter the value of b of the second equation : ");
	scanf("%d",&d);
	printf("\nEnter the value of c of the second equation : ");
	scanf("%d",&n);
	n=-n;
    if(!(a*d-b*c))
	{
		printf("\n\n!!!! Error :  ad-bc is Zero.");
		exit(0);
	}
 	x1=(m*d-b*n)/(a*d-b*c);
 	x2=(n*a-m*c)/(a*d-b*c);
	printf("\n\nThe Point of Intersection of the Two Line is (%.2f,%.2f) : ",x1,x2);
	s1=(-a/b);
    s2=-c/d;
	if(b!=0&&d!=0)
	{    s=(s1-s2)/(1+(s1*s2));
    	if(s<0)
        	s=-s;
    	printf("\n\nThe Angle Between Lines is : %.2f degrees ",atan(s)*180/3.14);
		return 0;
	}
	else if(b==0)
		s1=0;
    else if(d==0)
		s2=0;
	s=(s1-s2)/(1+(s1*s2));
    if(s<0)
       	s=-s;
    printf("\n\nThe Angle Between Lines is : %.2f degrees ",90-(atan(s)*180/3.14));
	return 0;
}