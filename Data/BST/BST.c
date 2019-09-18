#include <stdlib.h>
#include <stdio.h>
#include "BST.h"

struct node 
{ 
    int value; 
    struct node *left, *right; 
}; 
typedef struct node node;
struct Tree
{
    node *root;
};
static node *createNode(int item);
static node* insert( node* node, int value);
static AdtStatus searchNodes(node* ,int );
static node * minValueNode(node* node);
static node* deleteNode(node* root, int key) ;
static int destroyNodes(node* Node);
static void walkNodesPreOrder(node* current,printTree printByOrder);
static void walkNodesInOrder(node* current,printTree printByOrder);
static void walkNodesPostOrder(node* current,printTree printByOrder);


Tree *treeCreate()
{
    Tree *t;
    t=malloc(sizeof(Tree));
    if(t==NULL)
    {
        return NULL
    }
    t->root=NULL;
    return t;
}
AdtStatus insertToTree(Tree *t,int item)
{   
    if(t==NULL)
    {
        return AllocationError;
    }
    if(t->root==NULL)
    {
        t->root->value=item;
        t->root->left=NULL;
        t->root->right=NULL;
        return OK;
    }
    if (item < t->root->value) 
        t->root->left  = insert(t->root->left, item); 
    else if (item > t->root->value) 
        t->root->right = insert(t->root->right, item);    
    return OK; 
}
static node *createNode(int item) 
{ 
    node *temp =  malloc(sizeof( node)); 
    if(temp==NULL)
    {
        return NULL;
    }
    temp->value = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
static node* insert(node* node, int value) 
{ 
    if (value < node->value) 
        node->left  = insert(node->left, value); 
    else if (value > node->value) 
        node->right = insert(node->right, value);    
    return node; 
} 
AdtStatus searchTree(Tree *t,int item)
{
    if(t==NULL)
    {
        return AllocationError;
    }
    if(t->root->value==item)
    {
        return OK;
    }
    return searchNodes(t->root,item);
}
static AdtStatus searchNodes(node* Node,int item)
{
    if(Node==NULL)
    {
        return NotExist;
    }
    if(Node->value==item)
    {
        return OK;
    }
    return searchNodes(Node->left,item)|| searchNodes(Node->right,item);
}

AdtStatus deleteItem(Tree *t,int item)
{
    node* newRoot;
    if(t==NULL)
    {
        return AllocationError;
    }
    newRoot=deleteNode(t->root,item);
    t->root=newRoot;
    return OK;

}
static node* deleteNode(node* root, int key) 
{ 
    node *temp;
    if (root == NULL) 
    {
        return root; 
    }
    if (key < root->value) 
    {
        root->left = deleteNode(root->left, key); 
    }
    else if (key > root->value)
    {
        root->right = deleteNode(root->right, key); 
    }
    else
    { 
 
        if (root->left == NULL) 
        { 
            node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            node *temp = root->left; 
            free(root); 
            return temp; 
        } 
        temp = minValueNode(root->right); 
        root->value = temp->value; 
        root->right = deleteNode(root->right, temp->value); 
    } 
    return root; 
} 
static node* minValueNode(node* newnode) 
{ 
    node* current=newnode;
    while (current && current->left != NULL)
        current = current->left; 
    return current; 
}

AdtStatus destroyTree(Tree *t)
{  
    int result=0;
    if(t==NULL)
    {
        return AllocationError;
    }
    result=destroyNodes(t->root);
    if(result==1)
    {
        return OK;
    }
}
static int destroyNodes(node* Node)
{
    if(Node->right==NULL&&Node->left==NULL)
    {
        free(Node);
        return 1;
    }
    destroyNodes(Node->left);
    destroyNodes(Node->right);
    return 1;
}
AdtStatus walkTree(Tree *t,printTree printByOrder,int Order)
{
    node* current=t->root;
    if(t==NULL)
    {
        return AllocationError;
    }
    if(Order==1)
    walkNodesPreOrder(current,printByOrder);
    if(Order==2)
    walkNodesInOrder(current, printByOrder);
    if(Order==3)
    walkNodesPostOrder(current, printByOrder);
}
static void walkNodesPreOrder(node *root,printTree printByOrder)
{
     if (root != NULL) 
    {
     printByOrder(root->value); 
     printPreorder(root->left);   
     printPreorder(root->right); 
    }
}     
static void walkNodesInOrder(node *root,printTree printByOrder) /*ascending order*/
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printByOrder(root->value); 
        inorder(root->right); 
    } 
}
static void walkNodesPostOrder(node *root,printTree printByOrder) 
{ 
    if (root != NULL) 
    { 
     printPreorder(root->left);   
     printPreorder(root->right);
     printByOrder(root->value);  
    } 
}
