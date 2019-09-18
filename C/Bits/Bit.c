#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Bit.h"

static int ReqInt(int);


int calculate(BitFunc f,BitMap* BM,int n){
	return f(BM,n); 
}

BitMap* Create_BM(int NumberFitcher)
{
    BitMap *B1;
    int *arr;
    int NumberOfInt;
    B1=malloc(sizeof(BitMap*));
    if(B1==NULL)
    {
        return NULL;
    }
    if(NumberFitcher%(8*sizeof(int))==0)
    {
        NumberOfInt = (NumberFitcher/(8*sizeof(int))) ;
    }
    else
    {
        NumberOfInt = (NumberFitcher/(8*sizeof(int))) +1 ;
    }
    arr=calloc(NumberOfInt,sizeof(int));
    if(arr==NULL)
    {
        free(B1);
        return NULL;
    }
    B1->m_NumberFitcher=NumberFitcher;
    B1->m_arr=arr;
    return B1;
}

int BitOn(BitMap *BM,int n)
{   
    unsigned int num=1;
    int IntNumberLocation,indexBinary;
    if(n>(BM->m_NumberFitcher))
    {
        return 0;
    }
    IntNumberLocation=ReqInt(n);
   /* IntInTheLocation=BM->m_arr[IntNumberLocation]; */
    indexBinary=(n%(8*sizeof(int))==0)?(8*sizeof(int)):n%(8*sizeof(int));
    num=num<<indexBinary-1;
    BM->m_arr[IntNumberLocation]=BM->m_arr[IntNumberLocation]|num;
    toBinari(BM->m_arr[IntNumberLocation]);
    return 1;
}

int BitOff(BitMap *BM,int n)
{
    unsigned int num=1;
    int IntNumberLocation,indexBinary;
    if(n>BM->m_NumberFitcher)
    {
        return 0;
    }
    IntNumberLocation=ReqInt(n);
    indexBinary=(n%(8*sizeof(int))==0)?(8*sizeof(int)):n%(8*sizeof(int));
    num=num<<indexBinary-1;
    num=~num;
    BM->m_arr[IntNumberLocation]=BM->m_arr[IntNumberLocation]&num;
    toBinari(BM->m_arr[IntNumberLocation]);
    return 1;
}
int BitStat(BitMap *BM,int n)
{
    unsigned int num = 1;
    int IntNumberLocation,indexBinary;
    if(n>BM->m_NumberFitcher)
    {
        return -1;
    }
    IntNumberLocation=ReqInt(n);
    indexBinary=(n%(8*sizeof(int))==0)?(8*sizeof(int)):n%(8*sizeof(int));
    num=num<<indexBinary-1;
    num=BM->m_arr[IntNumberLocation]&num;
    toBinari(num);
    if(num=0)
    {
        return 0;
    }
    if(num>0)
    {
        return 1;
    }
}
static int ReqInt(int n)
{
    int IntLocation,NumberOfInt;
    NumberOfInt=n%(8*sizeof(int));
    if(NumberOfInt==0)
    {
        IntLocation=n/(8*sizeof(int));
    }
    else
    {
        IntLocation=n/(8*sizeof(int))+1;
    }
    return IntLocation;
}
void toBinari(int v)
{
    char a[100];
    int i = 0;
    while (v > 0)
    {
        a[i] = v % 2 + '0';
        v = v / 2;
        i++;
    }
    a[i]='\0';
         printf("this is the binary :  ");
         for (i = strlen(a) - 1; i >= 0; i--)
         {
             printf("%c", a[i]);
         }
}
void destroy (BitMap *B1)
{
    free(B1);
}