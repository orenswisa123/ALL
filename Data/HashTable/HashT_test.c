#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include"HashT.h"

int compareFunc1(void *, void *);
size_t hashfunc1(void *);
static void testFunc();
void hashPrint(void *);
void funcDestroyKey(void *);
void funcDestroyData(void *);
int testCreate();
int testInsert();
int testFind();

int main()
{
	testCreate();
	testInsert();
	testFind();
	testDelete();
	testDestroy();
	return 1;
}
int testCreate()
{
	HASHTBL *HM = NULL;
	size_t size=2;
	elementCompare testCompare = compareFunc1;
	elementHash hashtest = hashfunc1;
	destroyelem desKey=funcDestroyKey;
	destroyelem desData=funcDestroyData;
	elemntPrint hashPrint1=hashPrint;
	
	HM = hashtbl_create(size, hashtest, testCompare);
	if (HM == NULL)
	{
		printf("hashtable not created\n");
		return 0;
	}
	hashtbl_insert(HM, "213213", "oren");
	hashTableForEach(HM,hashPrint1);
	hashtbl_destroy(HM,desData,desKey);
	return 1;

}
int testInsert()
{
	HASHTBL *HM = NULL;
	size_t size=2;
	elementCompare testCompare = compareFunc1;
	elementHash hashtest = hashfunc1;
	destroyelem desKey=funcDestroyKey;
	destroyelem desData=funcDestroyData;
	elemntPrint hashPrint1=hashPrint;
	HM = hashtbl_create(size, hashtest, testCompare);
	hashtbl_insert(HM, "328865587", "margo");
	hashtbl_insert(HM, "213213", "oren");
	hashtbl_insert(HM, "deqw112", "rachek");
	hashtbl_insert(HM, "123", "ddaa");
	hashtbl_insert(HM, "213213", "yae");
	hashTableForEach(HM,hashPrint1);
	hashtbl_destroy(HM,desData,desKey);
	return 1;
}
int testFind()
{
	HASHTBL *HM = NULL;
	size_t size=2;
	char* strfound;
	elementCompare testCompare = compareFunc1;
	elementHash hashtest = hashfunc1;
	destroyelem desKey=funcDestroyKey;
	destroyelem desData=funcDestroyData;
	elemntPrint hashPrint1=hashPrint;
	HM = hashtbl_create(size, hashtest, testCompare);
	hashtbl_insert(HM, "328865587", "margo");
	hashtbl_insert(HM, "213213", "oren");
	hashtbl_insert(HM, "deqw112", "rachek");
	hashtbl_insert(HM, "123", "ddaa");
	hashtbl_insert(HM, "213213", "yae");
	strfound=(char*)hashtblFind(HM,"123",testCompare);
	if(strfound!=NULL)
	{
		printf("%s\n", strfound);
		return 1;
		hashtbl_destroy(HM,desData,desKey);
	}
	return 0;
}
int testDelete()
{
	HASHTBL *HM = NULL;
	int res=0;
	size_t size=2;
	char* strfound;
	elementCompare testCompare = compareFunc1;
	elementHash hashtest = hashfunc1;
	destroyelem desKey=funcDestroyKey;
	destroyelem desData=funcDestroyData;
	elemntPrint hashPrint1=hashPrint;
	HM = hashtbl_create(size, hashtest, testCompare);
	hashtbl_insert(HM, "328865587", "margo");
	hashtbl_insert(HM, "213213", "oren");
	hashtbl_insert(HM, "deqw112", "rachek");
	hashtbl_insert(HM, "123", "ddaa");
	hashTableForEach(HM,hashPrint1);
	res=hashtblDelete(HM, "1", desData, desKey);
	if(res==0)
	{
		printf("key not exist\n");
		hashtbl_destroy(HM,desData,desKey);
		return 0;
		
	}
	hashtbl_destroy(HM,desData,desKey);
	return 1;
}
int testDestroy()
{
		HASHTBL *HM = NULL;
	int res=0;
	size_t size=2;
	char* strfound;
	elementCompare testCompare = compareFunc1;
	elementHash hashtest = hashfunc1;
	destroyelem desKey=funcDestroyKey;
	destroyelem desData=funcDestroyData;
	elemntPrint hashPrint1=hashPrint;
	HM = hashtbl_create(size, hashtest, testCompare);
	hashtbl_insert(HM, "328865587", "margo");
	hashtbl_insert(HM, "213213", "oren");
	hashtbl_insert(HM, "deqw112", "rachek");
	hashtbl_insert(HM, "123", "ddaa");
	hashTableForEach(HM,hashPrint1);
	res=hashtbl_destroy(HM,desData,desKey);
	if(res==0)
	{
		printf("nothing to free, the HM is null\n");
		return 0;
	}
	else
	{
		printf("destory succses\n");
		hashTableForEach(HM,hashPrint1); /*wont print nothing*/
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
	char *stam = (char*) value;
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
