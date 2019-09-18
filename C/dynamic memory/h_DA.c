#include <stdio.h>
#include <stdlib.h>
#include "h_DA.h"


DA_t* createDA(int capacity)
{
	DA_t* Da1;
	Da1=(DA_t*)malloc(sizeof(DA_t));
	if(Da1==NULL)
		return NULL;
	else              /*(Da1!=NULL)*/
	{
		(*Da1).capacity=capacity;
		(*Da1).index=0;
		(*Da1).arr=malloc(capacity*sizeof(int));
		if((*Da1).arr==NULL)
		{
			free(Da1);
		}
		
	}
	return Da1;
}
int insert(DA_t* da_ptr,int num)
{
	if(da_ptr!=NULL)
	{
	int *temp=(da_ptr->arr);/*temporary pointer to not erase the original*/
	if((da_ptr->index)>=(da_ptr->capacity))
	{
		temp=realloc((da_ptr->arr),((da_ptr->capacity)*2)*sizeof(int));
		if(temp)  /*check if pointer is ok*/
		{
			(da_ptr->arr)=temp;
			(da_ptr->capacity)*=2;/*make capacity dual*/
			
		}
		else
		{
			return 0;
		}
	}

	da_ptr->arr[da_ptr->index]=num;
			((da_ptr->index))++;

	return 1;
	}
	return 0;
}

void printDA(DA_t* da_ptr)
{
	if(da_ptr!=NULL)
	{
		int i=0;
		for(i=0;i<(da_ptr->index);i++)
		{
			printf("%d ",da_ptr->arr[i]);
		}
		printf("\n");
	}
}
void destroyDA(DA_t* da_ptr)
{
	if(da_ptr!=NULL)
		{
		free(da_ptr->arr);
		free(da_ptr);
		}
}
	

