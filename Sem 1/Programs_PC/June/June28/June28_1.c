#include <stdio.h>
#include <limits.h>

int main()
{
	printf("\n\t\t ##### Memory Values #####");
	printf("\n\n   NAME\t\t        SIZE\t      MIN_VALUE\t\t\tMAX_VALUE\n");
	printf("int\t\t\t %ld \t     %d \t\t%d\n",sizeof(int),INT_MIN,INT_MAX);
	printf("short\t\t\t %ld \t       %d \t\t\t %d\n",sizeof(short),SHRT_MIN,SHRT_MAX);
	printf("long\t\t\t %ld \t%ld\t    %ld\n",sizeof(long),LONG_MIN,LONG_MAX);
	printf("unsigned int \t\t %ld \t\t  %d \t\t\t%u\n",sizeof(unsigned),0,UINT_MAX);
	printf("unsigned short\t\t %ld \t\t  %d \t\t\t  %d\n",sizeof(unsigned short),0,USHRT_MAX);
	printf("unsigned long\t\t %ld \t\t  %d \t\t   %lu\n",sizeof(unsigned long),0,ULONG_MAX);
	printf("char\t\t\t %ld \t\t%d \t\t\t  %d\n",sizeof(char),CHAR_MIN,CHAR_MAX);
	printf("signed char\t\t %ld \t        %d \t\t\t  %d\n",sizeof(signed char),SCHAR_MIN,SCHAR_MAX);
	printf("unsigned char\t\t %ld \t\t  %d \t\t\t  %d\n",sizeof(unsigned char),0,UCHAR_MAX);
	printf("long long\t\t %ld \t %lld \t   %lld\n",sizeof(long long),LLONG_MIN,LLONG_MAX);
	printf("unsigned long long\t %ld \t\t  %d \t\t   %llu\n",sizeof(unsigned long long),0,ULLONG_MAX);

	return 0;
}

