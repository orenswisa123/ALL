#include <stdio.h>

int palindrome_func(int x);
int main()
{
printf("%d\n",palindrome_func(19891));
}

int palindrome_func(x)
{
  int y,reverse=0;
 
  y=x;
 
  while (y != 0) 
	{
    	reverse=reverse*10;
    	reverse=reverse+y%10;
  	y = y/10;
  	}
 
  if (x==reverse)
    return 1;
  else
    return 0;
}
