
#include <stdio.h>
#include <stdlib.h>
#include "darray_void.h"

static void quicksort(darray* ,int ,int ,elementCompare);

struct darray{
    int m_index;
    int m_capacity;
    int m_initial_capacity;
    void** m_arr;
};


AdtStatus darrayCreate(darray **dArr, size_t initial_capacity)
{
    *dArr=malloc(sizeof(darray));
    if(*dArr==NULL)
    {
        return AllocationError;
    }
	(*dArr)->m_arr=malloc(initial_capacity*sizeof(void*));
    if((*dArr)->m_arr==NULL)
    {
        free(*dArr);
        return AllocationError;
    }
    (*dArr)->m_capacity=initial_capacity;
    (*dArr)->m_index=0;
    (*dArr)->m_initial_capacity=initial_capacity;
    

    return OK;
}
AdtStatus darrayDestroy(darray *dArr, elementDestroy destroyFunc, void *context)
{
    int i;
    if(dArr==NULL)
    {
        return AllocationError;
    }
    for(i=0;i<dArr->m_index;i++)
    {
        destroyFunc1(dArr->m_arr[i],context);
    }
    free(dArr->m_arr);
    free(dArr);
    return OK;
}
AdtStatus  darrayAdd(darray *dArr,  void  *_item)
{
    void** temp;
    if(dArr==NULL)
    {
        return AllocationError;
    }
    if(dArr->m_index==dArr->m_capacity)
    {
       temp=realloc(dArr->m_arr,(dArr->m_capacity)*2*sizeof(void*));
       if(temp==NULL)
       {
           return AllocationError;
       }
       dArr->m_arr=temp;
       dArr->m_capacity=(dArr->m_capacity)*2;
    }
    dArr->m_arr[dArr->m_index]=_item;
    (dArr->m_index)++;
    return OK;
}
AdtStatus  darrayDelete(darray *dArr,  void **_item)
{
    void **temp;
    if(dArr==NULL)
    {
        return AllocationError;
    }
    *_item=dArr->m_arr[dArr->m_index];
    if((dArr->m_index<=dArr->m_capacity*3/8)&&(dArr->m_initial_capacity!=dArr->m_capacity))
    {
        temp=realloc(dArr->m_arr,(dArr->m_capacity)*3/8*sizeof(void*));
        if(temp==NULL)
        {
            return AllocationError;
        }
        dArr->m_arr=temp;
        dArr->m_capacity=(dArr->m_capacity)/2;
    }
    (dArr->m_index)--;
    return OK;
}
AdtStatus   darrayGet(darray *dArr, size_t _index, void **_item)
{
    if (dArr == NULL)
    {
        return AllocationError;
    }
        if(dArr->m_index<=_index)
    {
        return IndexError;
    }
    *_item=dArr->m_arr[_index];
    return OK;
}
AdtStatus   darraySet(darray *dArr, size_t _index, void  *_item)
{
    if (dArr == NULL)
    {
        return AllocationError;
    }
    if(dArr->m_index<_index)
    {
        return IndexError;
    }
    dArr->m_arr[_index]=_item;
    return OK;
}
AdtStatus   darrayItemsNum(darray *dArr, int*  _numOfItems)
{
    if (dArr == NULL)
    {
        return AllocationError;
    }
    *_numOfItems=dArr->m_index;
    return OK;
}
AdtStatus darraySort(darray *dArr,elementCompare compareFunc)
{
    int low=0;
    int high=dArr->m_index;
    if(dArr==NULL)
    {
        return AllocationError;
    }
    quicksort(dArr,low,high-1,compareFunc);
}
static void quicksort(darray* dArr,int first,int last,elementCompare compareFunc1)
{
    int i, j, pivot;
    void *temp;
    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;
        while (i < j)
        {
            while (compareFunc1(dArr->m_arr[i], dArr->m_arr[pivot]) <= 0 && i < last)
                i++;
            while (compareFunc1(dArr->m_arr[j], dArr->m_arr[pivot]) > 0)
                j--;
            if (i < j)
            {
                temp = dArr->m_arr[i];
                dArr->m_arr[i] = dArr->m_arr[j];
                dArr->m_arr[j] = temp;
            }
        }
        temp = dArr->m_arr[pivot];
        dArr->m_arr[pivot] = dArr->m_arr[j];
        dArr->m_arr[j] = temp;
        quicksort(dArr, first, j - 1, compareFunc1);
        quicksort(dArr, j + 1, last, compareFunc1);
    }

}
/*AdtStatus printDarray(darray *dArr)
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

static void swap(void *xp, void *yp) 
{ 
    void* temp = *xp; 
    *xp = *yp; 
    *yp = temp;
}*/