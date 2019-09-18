#include<stdio.h>
#include<stdlib.h>
#include"HashT.h"

int compareFunc1(void *, void *);
size_t hashfunc1(void *);
static void testFunc();
void hashPrint(void *);
void funcDestroyKey(void *);
void funcDestroyData(void *);


int initialHashTable(HASHTBL** HM)
{
	size_t size=4127015;

	elementCompare testCompare = compareFunc1;
	elementHash hashtest = hashfunc1;
	destroyelem desKey=funcDestroyKey;
	destroyelem desData=funcDestroyData;
	elemntPrint hashPrint1=hashPrint;
	*HM = hashtbl_create(size, hashtest, testCompare);
	if (*HM == NULL)
	{
		printf("hashtable not created\n");
		return 0;
	}
    return 1;
}

size_t hashfunc1(void *elemKey)
{
    unsigned char *str1 = (unsigned char *)elemKey;
    unsigned long hash = 5381;
    int c;

    while ((c = *str1++) != 0)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;

}
int compareFunc1(void *_elemA, void *_elemB)
{
    char* str1=(char*)_elemA;
    char* str2=(char*)_elemB;
    if(strcmp(str1,str2)==0)
    {
        return 0;
    }
    return -1;
}

void hashPrint(void *value)
{
	unsigned char *stam = (unsigned char*) value;
	printf("%s\n", stam);
}
void funcDestroyKey(void *key)
{
	unsigned char* str= (unsigned char*) key;
	
}
void funcDestroyData(void *data)
{
	unsigned char* str= (unsigned char*) data;
	
}