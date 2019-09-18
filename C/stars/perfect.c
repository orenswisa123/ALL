#include <stdio.h>

int perfect_func(int x);
int main()
{
	printf("%d\n",perfect_func(6));
}

int perfect_func(x)
{
	int i,sum=0;
	for(i=1;i<x/2+1;i++)
	{
		if(x%i==0)
		{
			sum=sum+i;	
		}
	}
	return (sum==x)?1:0;
	/*{
		return 1;
	}
	return 0;*/ /*the long way to return*/
}
