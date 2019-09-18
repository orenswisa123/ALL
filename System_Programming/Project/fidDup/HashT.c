#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include"HashT.h"


struct hashnode_s 
{
    void *key;
    void *data;
    struct hashnode_s *next;
};


struct hashtbl
{
    size_t size;
    hashnode_s **nodes;
    elementHash  hashfunc;
    elementCompare compareFunc;
};



static void createNode(HASHTBL *HM, hashnode_s *node,void* data,size_t hash,void* key);

HASHTBL *hashtbl_create(size_t size, elementHash hashFunc,elementCompare compareFunc)
{
    HASHTBL *HM;
    int i;
    HM=malloc(sizeof(HASHTBL));
    if(HM==NULL)
    {
        return NULL;
    }
    if(size<0)
    {
        return NULL;
    }
    HM->size=size;
    HM->nodes=calloc(size,sizeof(hashnode_s*));
    if(HM->nodes==NULL)
    {
        free(HM);
        return NULL;
    }
    HM->hashfunc=hashFunc;
    HM->compareFunc=compareFunc;
    return HM;
}
int hashtbl_destroy(HASHTBL *HM,destroyelem funcDestroyData,destroyelem funcDestroyKey) 
{
    size_t n;
    hashnode_s *node, *oldnode;
    if(HM==NULL)
    {
        return 0;
    }
    for (n = 0; n < HM->size; ++n)
    {
        node = HM->nodes[n];
        while (node)
        {
            funcDestroyKey(node->key);
            funcDestroyData(node->data);
            oldnode = node;
            node = node->next;
            free(oldnode);
        }
    }
    free(HM->nodes);
    free(HM);
    return 1;
}

int hashtbl_insert(HASHTBL *HM, void *key, void *data)
{
    int result=0;
    hashnode_s *node;
    size_t hash;
    if(HM==NULL)
    {
        return 0;
    }
    hash = (HM->hashfunc(key)) % (HM->size); 
    if(HM->nodes[hash]!=NULL)
    {
        node=HM->nodes[hash];
        while (node != NULL)
        {

            if (HM->compareFunc(node->key, key) == 0)
            {
                /*node->data = data;*/
                printValue(HM, key, data);
                return 1;
            }
            node = node->next;
        }
    }    
    node = malloc(sizeof(hashnode_s));
    if(node==NULL)
    {
        return -1;
    }
    createNode(HM,node,data,hash,key);
    return 1;
}    
static void createNode(HASHTBL *HM, hashnode_s *node,void* data,size_t hash,void* key)
{
    node->data = data;
    node->key = key;
    node->next = HM->nodes[hash];
    HM->nodes[hash] = node;
}
void* hashtblFind(HASHTBL *HM, void *key,elementCompare compareFunc)
{
    hashnode_s *node;
    size_t hash = (HM->hashfunc(key)) % (HM->size);
    
    if (HM == NULL)
    {
        return NULL;
    }
    if (HM->nodes[hash] != NULL)
    {
        node = HM->nodes[hash];
        while (node)
        {
            if (compareFunc(node->key, key) == 0)
            {
                return node->data;
            }
            node = node->next;
        }
    }
    return NULL;
} 
int hashtblDelete(HASHTBL *HM, void *key,destroyelem funcDestroyData,destroyelem funcDestroyKey)
{
    size_t IndexBucket=0;
    hashnode_s *next;
    hashnode_s *last=NULL;
    if(HM==NULL)
    {
        return 0;
    }
    IndexBucket=(HM->hashfunc(key))%(HM->size);
    next=HM->nodes[IndexBucket];
    while((next!=NULL) && (next->key!=NULL) && (HM->compareFunc(key,next->key)!=0))
    {
        last=next;
        next=next->next;
    }
    if(next!=NULL)
    {
        if(last==NULL)
        {
            if(next->next!=NULL)
            {
                HM->nodes[IndexBucket]=next->next;
                funcDestroyKey(next->key);
                funcDestroyData(next->data);
            }
            else
            {
                HM->nodes[IndexBucket]=NULL;
                funcDestroyKey(next->key);
                funcDestroyData(next->data);
            }
        }
        else if (next->next != NULL)
        {
            last->next = next->next;
            funcDestroyKey(next->key);
            funcDestroyData(next->data);
            }
            else
            {
                last->next = NULL;
                funcDestroyKey(next->key);
                funcDestroyData(next->data);
            }
        return 1;
    }
    else
    {
        return 0;
    }
   }

int hashTableForEach(HASHTBL *HM,elemntPrint printFunc)
{
    int i;
    hashnode_s *node;
    if(HM==NULL)
    {
        return 0;
    }
    for(i=0;i<HM->size;i++)
    {
        node=HM->nodes[i];
        while(node!=NULL)
        {
            printFunc(node->data);
            node=node->next;
        }
    }
    return 1;
	    
}

printValue(HASHTBL* HM, void* key, void* data)
{
    void* oldData;
    oldData = hashtblFind(HM, key, HM->compareFunc);
    hashPrint(oldData);
    hashPrint(data);
}