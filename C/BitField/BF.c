#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BF.h"


int pack(char* str)
{   
    int size=strlen(str);
    int i,index=0;
    for(i=0;i<size;i=i+2)
    {
        str[index]=(str[i]-'a')<<4;
        str[index]|=(str[i+1]-'a');
        index++;
        decToBinary(str[i]);
        printf("\n");

    }
    return size;
}

int packfield(char* str)
{
    union U LR;
    int size = strlen(str);
    int i, index = 0;
    for (i = 0; i < size; i += 2)
    {
        LR.LRB.L=str[i]-'a';
        LR.LRB.R=str[i+1]-'a';
        str[index]=LR.c;
        index++;
        decToBinary(str[i]);
        printf("\n");
    }
    return size;
}
void decToBinary(char c)
{
    int i=0;
     for (i = 0; i < 8; i++) {
     printf("%d", !!((c << i) & 0x80));
 }
}



