
#include <stdio.h>
#include <stdlib.h>
#include "darray_int.h"

int main()
{   darray *ptrDarr;
    int item,i,index,numOfItems;
    int initial_capacity;
    printf("Enter initial_capacity\n");
    scanf("%d",&initial_capacity); 
    darrayCreate(&ptrDarr, initial_capacity);
    printf("Enter item to add\n");
    scanf("%d",&item); 
    while(item !=-1)
    {   darrayAdd(ptrDarr,item);
        printf("Enter item to add\n");
        scanf("%d",&item); 
       
    }
    printDarray(ptrDarr);

    
    darrayDelete(ptrDarr,&item);
    printDarray(ptrDarr);
    darrayDelete(ptrDarr,&item);
    printDarray(ptrDarr);
    darrayItemsNum(ptrDarr,&numOfItems);
    printf("num of items=%d\n",numOfItems);
    printf("Enter index to get\n");
    scanf("%d",&index); 
    darrayGet(ptrDarr, index, &item);
    printf("item=%d\n",item);
    printf("Enter index to set\n");
    scanf("%d",&index); 
    item=5;
    darraySet(ptrDarr, index,item);
    printDarray(ptrDarr);
    darraySort(ptrDarr);
    printDarray(ptrDarr);
    
    return 0;
}