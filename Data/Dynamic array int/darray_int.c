
#include <stdio.h>
#include <stdlib.h>
#include "darray_int.h"

static void swap(int *, int *);

struct darray{
    int _index;
    int _capacity;
    int _initial_capacity;
    int *_arrNum;
};


AdtStatus darrayCreate(darray **dArr, size_t initial_capacity)
{
    *dArr=malloc(sizeof(darray));
    if(dArr==NULL)
    {
        return AllocationError;
    }
	(*dArr)->_arrNum=malloc(initial_capacity*sizeof(int));
    if((*dArr)->_arrNum==NULL)
    {
        free(*dArr);
        return AllocationError;
    }
    (*dArr)->_capacity=initial_capacity;
    (*dArr)->_index=0;
    (*dArr)->_initial_capacity=initial_capacity;
    

    return OK;
}
AdtStatus darrayDestroy(darray *dArr)
{
   /* if(dArr==NULL) need check
    {

    } */
    free(dArr->_arrNum);
    free(dArr);
    return OK;
}

AdtStatus  darrayAdd(darray *dArr,  int  _item)
{
    int *temp;
    if(dArr==NULL)
    {
        return AllocationError;
    }
    if(dArr->_index>=dArr->_capacity)
    {
       temp=realloc(dArr->_arrNum,(dArr->_capacity)*2*sizeof(int));
       if(temp==NULL)
       {
           return AllocationError;
       }
       dArr->_arrNum=temp;
       dArr->_capacity=(dArr->_capacity)*2;
    }
    dArr->_arrNum[dArr->_index]=_item;
    (dArr->_index)++;
    return OK;
}
AdtStatus   darrayDelete(darray *dArr,  int* _item)
{
    int *temp;
    if(dArr==NULL)
    {
        return AllocationError;
    }
    _item=&dArr->_arrNum[dArr->_index];
    if((dArr->_index<=dArr->_capacity*3/8)&&(dArr->_initial_capacity!=dArr->_capacity))
    {
        temp=realloc(dArr->_arrNum,(dArr->_capacity)*3/8*sizeof(int));
        if(temp==NULL)
        {
            return AllocationError;
        }
        dArr->_arrNum=temp;
        dArr->_capacity=(dArr->_capacity)/2;
    }
    (dArr->_index)--;
    return OK;
}
AdtStatus   darrayGet(darray *dArr, size_t _index, int *_item)
{
    if (dArr == NULL)
    {
        return AllocationError;
    }
        if(dArr->_index<_index)
    {
        return IndexError;
    }
    *_item=dArr->_arrNum[_index];
    return OK;
}

AdtStatus   darraySet(darray *dArr, size_t _index, int  _item) 
{
    if (dArr == NULL)
    {
        return AllocationError;
    }
    if(dArr->_index<_index)
    {
        return IndexError;
    }
    dArr->_arrNum[_index]=_item;
    return OK;
}
AdtStatus   darrayItemsNum(darray *dArr, int*  _numOfItems)
{
    if (dArr == NULL)
    {
        return AllocationError;
    }
    *_numOfItems=dArr->_index;
    return OK;
}
AdtStatus darraySort(darray *dArr)
{
    int i, j;
    if (dArr == NULL)
    {
        return AllocationError;
    }
    for (i = 0; i < dArr->_index - 1; i++)
    {
        for (j = 0; j < dArr->_index - i - 1; j++)
        {
            if (dArr->_arrNum[j] > dArr->_arrNum[j + 1])
            {
                swap(&dArr->_arrNum[j], &dArr->_arrNum[j + 1]);
            }
        }
    }

}
AdtStatus printDarray(darray *dArr)
{
    int i;
    if ((dArr) == NULL)
    {
        return   AllocationError;
        
    }  
    for(i=0;i<dArr->_index;i++)
    {
        printf("%d",dArr->_arrNum[i]);
    }
    printf("\n");
    return  OK;
}

static void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp;
}