
#include <stdio.h>
#include <stdlib.h>
#include "darray_void.h"
typedef enum menu{createArr=1,destroyArr=2,addStruct=3,deleteStruct=4,get=5,set=6,returnSize=7,sortArr=8}menu;
int printMenu();
void destroyFunc1(void*, void*);
void printPoint(void *_elem);
int compareFunc1(void *, void *);


typedef struct 
{
    int x;
    int y;
}points;

points* createStruct();

int main()
{   
    int opt=10,numOfItems,error;
    FILE *fp;
    void* itemAdd;
    void *itemDel;
    void* getItem;
    void* itemSet;
    void* itemDes;
	int size=0, idxGet=0,idxSet=0;
	darray* darr;
    fp=fopen("fileDelete.txt", "a");

	while(opt!=-1)
	{
		opt=printMenu();
		
		switch(opt)
		{
			case createArr:
			{
				printf("Insert initial capacity of array\n\n");
				scanf("%d",&size);
				darrayCreate(&darr,size);
				break;
			}
			case destroyArr:
			{
				darrayDestroy(darr,destroyFunc1,fp);
				break;
			}
			case addStruct:
			{
				itemAdd=createStruct();
				darrayAdd(darr,itemAdd);
				break;
			}
			case deleteStruct:
			{
				darrayDelete(darr,&itemDel);
				break;
			}
			case get:
			{
				printf("Insert index of item that you want to get\n\n");
				scanf("%d",&idxGet);
				error=darrayGet(darr,idxGet,&getItem);
                if(error!=2)
                {
                printPoint(getItem);
                }
				break;
			}
			case set:
			{
				printf("Insert a index of item you want to set\n\n");
				scanf("%d",&idxSet);
                itemSet=createStruct();
                darrayGet(darr,idxSet, &getItem); /*free the previous item on this index*/
                free(getItem);
				darraySet(darr, idxSet, itemSet);
				break;
			}
			case returnSize:
			{
				darrayItemsNum(darr, &numOfItems);
                printf("%d\n", numOfItems);
				break;
			}
			case sortArr:
			{
				darraySort(darr,compareFunc1);
				break;
			}
            default:
            break;
		}
	}
    fclose(fp);
	return 1;
}

points* createStruct()
{
    int x,y;
    points* pointptr;
    pointptr=malloc(sizeof(points));
    if(pointptr==NULL)
    {
        return NULL;
    }
    printf("enter x : \n");
    scanf("%d" , &x);
    printf("enter y : \n");
    scanf("%d" , &y);
    pointptr->x=x;
    pointptr->y=y;
    return pointptr;
}
int compareFunc1(void *_elemA, void *_elemB)
{
    points* pointA=(points*)_elemA;
    points* pointB=(points*)_elemB;
    int result = pointA->x + pointA->y - pointB->x - pointB->y;
    return result;
}

void destroyFunc1(void *_elem, void *context)
{
    FILE *fp=(FILE*)context;
    points* castPtr=(points*)_elem;
    if(fp!=NULL)
    {
        fprintf(fp, "the x cordinate is %d : \n", castPtr->x);
        fprintf(fp, "the y cordinate is %d : \n", castPtr->y);
        free(castPtr);
    }
    
}

void printStruct(void *_elem)
{
    points* castPtr=(points*)_elem;
    printf("the x cordinate is %d : \n", castPtr->x);
    printf("the y cordinate is %d : \n", castPtr->y);
}

int printMenu()
{
    int opt;
    printf("1:\tcreate array\n\n");
    printf("2:\tdestroy array\n\n");
    printf("3:\tadd a point to the end\n\n");
    printf("4:\tdelete a point from array\n\n");
    printf("5:\tget a point\n\n");
    printf("6:\tset a point\n\n");
    printf("7:\treturn size of arr\n\n");
    printf("8:\tsort the array\n\n");
    printf("press -1 to stop \n");
    scanf("%d", &opt);
    return opt;
}
void printPoint(void *_elem)
{
    points * n=(points*)_elem;
    printf("%d ",n->x);
    printf("%d\n",n->y);
    
}