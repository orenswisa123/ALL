#include <stdio.h>
#include <stdlib.h>
int* insert(int,int*,int*,int*);


int main()
{
	int j=0,num=0;
	int* ip,capacity,i;
	i=0;
	capacity=6;
	ip=malloc(capacity*sizeof(int));
	printf("enter number: \n");
	scanf("%d",&num);


	while(num!=-5)
	{
		ip=insert(num,ip,&i,&capacity);
		printf("enter number: \n");
		scanf("%d",&num);
	}

	for(j=0;j<capacity;j++)
	printf("%d",ip[j]);
	free(ip);
	return 1;
}

int* insert(int n,int* ptr,int* idx,int* cap)
{
	int*temp=ptr;
	if(*(idx)>=*cap)
	{
		temp=realloc(ptr,(*cap*2)*sizeof(int));
		if(temp!=NULL)/*check if pointer is ok*/
		{
			ptr=temp;
			(*cap)*=2;/*make capacity dual*/
		}
		else
		{
			return ptr;
		}
	}

	ptr[*idx]=n;
	(*idx)++;

	return ptr;
}

