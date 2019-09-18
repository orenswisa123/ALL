#ifndef H_BST
#define H_BST
#include <stdlib.h>
typedef enum  {NotExist,OK, AllocationError} AdtStatus; 
typedef void (*printTree)(int);
typedef struct Tree Tree;
Tree *treeCreate();
AdtStatus insertToTree(Tree *t,int item);
AdtStatus searchTree(Tree *t,int item);
AdtStatus deleteItem(Tree *t,int item);
AdtStatus walkTree(Tree *t,printTree printByOrder,int Order);

#endif
