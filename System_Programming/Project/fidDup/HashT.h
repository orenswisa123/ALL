#ifndef HASH_TABELE_INCLUDE_GUARD
#define HASH_TABELE_INCLUDE_GUARD
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef int (* elementCompare)(void *_elemA, void *_elemB);
typedef size_t (*elementHash)(void *elemKey);
typedef void (*elemntPrint)(void* elemP);
typedef void (*destroyelem)(void*);

typedef struct hashnode_s hashnode_s;

typedef struct hashtbl HASHTBL;


HASHTBL *hashtbl_create(size_t size, elementHash hashFunc,elementCompare compareFunc);
int hashtbl_destroy(HASHTBL *hashtbl,destroyelem funcDestroyData,destroyelem funcDestroyKey);
int hashtbl_insert(HASHTBL *hashtbl, void *key, void *data);
int hashtblDelete(HASHTBL *hashtbl, void *key,destroyelem funcDestroyData,destroyelem funcDestroyKey);
int hashTableForEach(HASHTBL *HM , elemntPrint printFunc);
void* hashtblFind(HASHTBL *HM, void *key,elementCompare compareFunc);


#endif