#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int Encrypt()
{
	int Input, Pro[4],sub=0;
	printf("\nEnter the number(only four digits) : ");
	scanf("%d",&Input);
	for(int i=3;i>=0;i--)
	{
	Pro[3-i]=(Input/(pow(10,i)))-sub;
	sub+=Pro[3-i]*pow(10,i);
	printf("\n%d\n%d",&(Pro[3-i]),&sub);
	}



	
	return;
}


int Decrypt()
{




}


int main()
{
	int out; 
	printf("\n\t\t ##### Basic Encryption #####");
	printf("\nEnter 1 for Encryption\nEnter 2 for Decryption\nEnter your choice : ");
	scanf("%d",&out);
	switch(out)
	{
		case 1: out=Encrypt(); break;
		case 2: out=Decrypt(); break;
		default: printf("\n\nError!!! Invalid choice.");  exit(0);
	}
	printf("\n\nThe Output value is : %d \n",out);
	return 0;
}
