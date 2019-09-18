#include <stdio.h>
int func_1(int);
int func_2(int);
int func_3(int);

int main()
{
	func_2(4);
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
