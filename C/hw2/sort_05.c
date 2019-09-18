#include<stdio.h>

int sort_05_func(int, int *);



int main()
{
	int array[11]={3,6,8,3,9,12,45,9,12,56,12};
	printf("%d\n",sort_05_func(11,array));
}



sort_05_func(int size,int *ptr)
{
	int i,j,cur_max=1,sum_max=0,most_num=*ptr,temp=0;
	for(i=0;i<size;i++)
	{	
		if(ptr[i]==0)
		{
		continue;
		}
		else
			{
			for(j=i+1;j<size;j++)
			{
				if(ptr[i]==ptr[j])
				{
					cur_max++;
					ptr[j]=0;
				}
			}
		}
		if(cur_max>sum_max)
		{
			most_num=ptr[i];
			sum_max=cur_max;
		}
	}
	return most_num;	
					
					
}

