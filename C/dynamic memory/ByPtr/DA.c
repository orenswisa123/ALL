#include <stdio.h>
#include <stdlib.h>
#include "h_DA.h"

int main()
{
	int capacity=0;
	int *num_ptr=NULL,*temp=NULL;
	DA_t* Da1= NULL;
	temp=malloc(sizeof(int*));	
	if(temp!=NULL)
	{
   		num_ptr=temp;
	}
	printf("enter capacity: ");
	scanf("%d",&capacity);	
	Da1=createDA(capacity);
	
	
	printf("enter number: \n");
	scanf("%d",num_ptr);
	while(*num_ptr!=-5)
	{
		insert(Da1,num_ptr);
		temp=malloc(sizeof(int));	
		if(temp!=NULL)
		{
			num_ptr=temp;
		}
		else
		{
			free(Da1);
			return 0;
		}
		printf("enter number: \n");
		scanf("%d",num_ptr);
	}
	
	printDA(Da1);
	destroyDA(Da1);
	
	
	return 0;
}

