#include <stdio.h>
int up_func(int x);
int main()
{
printf("%d\n",up_func(5));
}


int up_func(x)
{
int y,z,temp=0;
 
  y=x;
 
  while (y>0) 
	{
    	temp=y%10;/* temp=5*/
    	y=y/10;/*y =124*/
   	z=y%10; /*4*/
	if(z>temp)
	{
	return 0;
  	}
	}	
 
	return 1;
}
