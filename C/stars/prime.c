#include<stdio.h>
int prime_func(int x);
int main()
{
printf("%d\n",prime_func(7));
}

int prime_func(x)
{
	int i,ans=1;
	for(i=2;i<=(x/2)+1;i++)
	{
		if(x%i==0)
		{
		ans=0;
		}
	}
	return ans;
}
	
