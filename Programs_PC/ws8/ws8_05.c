#include <stdio.h>

int main()
{
	char c = 'Z';
	char *cp = &c;
	printf("cp is 0x%08x\n", cp);
	printf("The character at cp is%c\n", *cp);
	cp = cp + 1;
	printf("cp is 0x%08x\n", cp);
	cp = cp + 1;
	printf("cp is 0x%08x\n", cp);

	int i = 80;
	int *ip = &i;
	printf("ip is 0x%08x\n", ip);
	printf("The number at ip is%d\n", *ip);
	ip = ip + 1;
	printf("cp is 0x%08x\n", ip);
	ip = ip + 1;
	printf("cp is 0x%08x\n", ip);

	float f = 80.5;
	float *fp = &f;
	printf("fp is 0x%08x\n", fp);
	printf("The number at ip is %f\n", *fp);
	fp = fp + 1;
	printf("fp is 0x%08x\n", fp);
	fp = fp + 1;
	printf("fp is 0x%08x\n", fp);

	double d = 80.5;
	double *dp = &d;
	printf("dp is 0x%08x\n", dp);
	printf("The number at dp is %lf\n", *dp);
	dp = dp + 1;
	printf("dp is 0x%08x\n", dp);
	dp = dp + 1;
	printf("dp is 0x%08x\n", dp);
	return 0;
}
