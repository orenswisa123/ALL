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

int main()
{
    testFunc();
    return 0;
}
void testFunc()
{

	int choice=0;
	HASHTBL *HM = NULL;
	elemntPrint hashPrint1=hashPrint;
	elementCompare testCompare=compareFunc1;
	elementHash hashtest=hashfunc1;
	destroyelem desKey=funcDestroyKey;
	destroyelem desData=funcDestroyData;
	
	HM = hashtbl_create(2, hashtest, testCompare);
	hashtbl_insert(HM, "328865587", "margo");
	hashtbl_insert(HM, "213213", "oren");
	hashtbl_insert(HM, "deqw112", "rachek");
	hashtbl_insert(HM, "123", "ddaa");
	/*hashtblDelete(HM,"328865587",desData,desKey);*/
	hashTableForEach(HM,hashPrint1);

	do
	{
		printf("\nChoose Function:\n");
		printf("1.\n");
		printf("2.\n");
		printf("3.\n");
		printf("4.\n");
		printf("5.Exit\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			printf("GoodBye!\n");
			break;
		default:
			break;
		}
	} while (choice !=5);

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
