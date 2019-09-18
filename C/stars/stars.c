#include <stdio.h>
int func_1(int);
int func_2(int);
int func_3(int);

int main()
{
	func_1(6);
	printf("\v");
	func_2(4);
	printf("\v");
	func_3(6);
}

int func_1(int x)
{
	int i,j;
	for(i=0;i<x;i++)
	{
		for(j=0;j<=i;j++)
		{
			printf("*");
		}
	printf("\n");
	}
return 0;
}


int func_2(int x)
{
	int i,j;
	for(i=0;i<x;i++)
	{
		for(j=0;j<=i;j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for(i=x-1;i>0;i--)
	{
		for(j=0;j<i;j++)
		{
			printf("*");
		}
		printf("\n");
	}
return 0;		
}

int func_3(int x)
{
	int i,j,k,space=x-1;
	for(i=0;i<x;i++)
	{
		for(j=0;j<space;j++)
		{
			printf(" ");
		}
		space--;
		printf("*");
		for(k=j+1;k<x;k++)
		{
			printf("**");
		}		
		printf("\n");
	}
return 0;
}
