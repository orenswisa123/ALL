#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int random_lotto(int *);
int random();
int same_num(int *);

int main()
{
	int i;
	int arr[6];
	srand (time(NULL));
	for(i=0;i<6;i++)
	{
		arr[i] = random();
		printf("%d\n",arr[i]);
	}
	same_num(arr);
	random_lotto(arr);
	return 1;
}

int random()
{
	int n1;
	n1 = (rand()%49)+1;
	return n1;
}

int same_num(int arr[])
{
	int i, j; 
	printf(" if there same numbers on the array, we lottery again "); 
	for(i = 0; i < 6; i++) 
	{
		for(j = i+1;j<6;j++) 
		{
      		if(arr[i] == arr[j]) 
      		{
        		printf(" %d is repeat", arr[i]); 
        	}
        }
	}
}



int random_lotto(int arr[])
{
	char lotto[5][10];
	int i,j,k=1,r,c;
	for(i=0;i<5;i++)
	{
		for(j=0;j<10;j++)
		{
			lotto[i][j]='-';
		}
	}
	/* print numbers
	for(i=0;i<5;i++)
	{
		printf("\n");
		for(j=0;j<10;j++)
		{
			printf("%d\t",lotto[i][j]);
		}
	}*/
	for(i=0;i<5;i++)
	{
		for(j=0;j<10;j++)
		{
			for(k=0;k<6;k++)
			{
				if(arr[k]>10)
				{
					r=arr[k]/10;
				}
				if(arr[k]<10)
				{
					r=0;
				}
				c=arr[k]%10;
				lotto[r][c]='+';
				
			}
		}
	}
	/* print plus or minus*/
	for(i=0;i<5;i++)
	{
		printf("\n");
		for(j=0;j<10;j++)
		{
			printf("%c\t",lotto[i][j]);
		}
	}
	return 1;
}

