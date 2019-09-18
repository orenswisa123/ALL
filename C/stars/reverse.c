#include <stdio.h>

int reverse_func(int x);
int main()
{
 printf("%d",reverse_func(1503));
}

int reverse_func(x)
{
  int y,reverse=0;
 
  y=x;
 
  while (y != 0) 
	{
	reverse=reverse*10;
	reverse=reverse+y%10;
	y=y/10;
	}
 
	return reverse;
}
