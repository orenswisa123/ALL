#include <stdio.h>
#include<string.h>
#include <math.h>
#include<stdlib.h>
#include"Bitwise.h"


static void toBinari(unsigned int v);

char my_compliment(char c)
{
    unsigned int num;
    unsigned char b=255;
    c=c^b;
    num=c;
    toBinari(num);
    return c;
}
char RotateByNum(char c,int n)
{
    int i;
    unsigned int num;
    char temp=c;
    temp=temp<<(sizeof(char)-n);
    c=c>>n;
    c=c|temp;
    num=c;
    toBinari(num);
    return c;
    
}


int SetBitsOne(char w,int i,int j,int value)
{
    int index=1;
    unsigned int num;
    int k;
    for(k=0;k<sizeof(int)*8-1;k++)
    {
        index=index<<1;
        index+=1;
    }
    index=index<<j;
    index=index>>i;
    w=w|index;
    num=w;
    toBinari(num);
    return num;
}

int SetBitZero(char w,int i,int j,int value)
{
    int index=1;
    unsigned int num;
    int k;
    for(k=0;k<sizeof(int)*8-1;k++)
    {
        index=index<<1;
        index+=1;
    }
    index=index<<j;
    index=index>>i;
    index=~index;
    w=w&index;
    num=w;
    toBinari(num);
    return num;
}
int setXYPN(unsigned char* x,int p,int n,unsigned char* y)
{
    int k;
   unsigned int num;
   unsigned char temp=1;
       for(k=0;k<sizeof(unsigned char)*8-1;k++)
    {
        temp=temp<<1;
        temp+=1;
    }
    if((x!=NULL)&&(y!=NULL))
    {

        temp = temp << (p - n);
        temp = ~temp;
        *x = *x & temp;
        *y = *y << (8 - n);
        *y = *y >> (8 - p);
        *x = *y | *x;
     
        num=(unsigned int)(*x);
        toBinari(num);
    
     return 1;
   }
  return 0;
   
}

static void toBinari(unsigned int v){
       char a[256];
       int i=0,j=0;
    
       while(v>0){
        a[i]=v%2+'0';
         v=v/2;
         i++;
         
       } 
    a[i]='\0';
         
         for(i=8;i>=0;i--){
            if(i<=strlen(a)){
              printf("%c",a[i]);
            }else{
              printf("%c",'0');
            }
         }
        
}
