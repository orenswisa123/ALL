#include <stdio.h>
#include <stdlib.h>

struct Node{ 
    int data; 
    struct Node* next; 
};
typedef struct Node Node;

Node *makeList(int);
void listNodePrint(Node*);
Node *flipList(Node*);
Node *middleList(Node *);
int loopFinder(Node *);
Node *comminNode(Node *,Node *);

int main()
{
    Node *list;
    Node *H1,*H2;
    int len=11;
    list=makeList(len);
    listNodePrint(list);
    list=flipList(list);
    listNodePrint(list);
    middleList(list);
    loopFinder(list);
    comminNode(H1,H2);
   /* destroyList(list);*/

    return 1;
}
Node *makeList(int len)
{
    int i;
    Node * head = NULL;
    Node * currNode = NULL;
    head=malloc(sizeof(Node));
    if(head)
    {
        head->data=1;
        head->next=NULL;
        currNode= head;

        for(i=1;i<len;i++)
        {
            currNode->next=malloc(sizeof(Node));
            currNode=currNode->next;
            currNode->data= i+1;
        }
        currNode->next=NULL;
    }
    return head;
}

void listNodePrint(Node *list) 
{ 
     Node *currNode=list;
    while (currNode != NULL) { 
        printf(" %d \n", currNode->data); 
        currNode = currNode->next; 
    } 
} 
destroyList(Node *list)
{
    Node * curr=list->next;
    while(curr->next!=NULL)
    {
        free(list);
        list=curr->next;
        curr=list->next;
    }
}

Node *flipList(Node *list)
{
    Node *currNode=list;
    Node *nextNode=NULL;
    Node *prevNode=NULL;
    while(currNode!=NULL)
    {
        nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    return prevNode;
}

Node *middleList(Node *list)
{
    Node *currNode1=list;
    Node *currNode2=list;
    while (currNode2 != NULL&&currNode2->next!=NULL)
    {
        currNode1=currNode1->next;
        currNode2=currNode2->next->next;
        
    }
    printf("%d\n" ,currNode1->data);
    return currNode1;
}
int loopFinder(Node *list)
{
    Node *currNode1=list;
    Node *currNode2=list; 
        while (currNode2 != NULL&&currNode2->next!=NULL)
    {
        currNode1=currNode1->next;
        currNode2=currNode2->next->next;
        if(currNode1==currNode2)
        {
            return 1;
        }
    }
    return 0;
}
Node *comminNode(Node *H1, Node *H2)
{
    Node *currNode1=H1;
    Node *newCurrNode1=H1;
    Node *currNode2=H2;
    Node *newCurrNode2=H2;
    int len1=0,len2=0,i,result;
    while(currNode1!=NULL)
    {
        len1++;
        currNode1=currNode1->next;
    }
        while(currNode2!=NULL)
    {
        len2++;
        currNode2=currNode2->next;
    }
    if(len2>len1)
    {
        result = len2 - len1;
        for (i = 0; i < res - 1; i++)
        {
            newCurrNode2 = newCurrNode2->next;
        }
    }
    else if(len1>len2)
    {
        result=len1-len2;
        for (i = 0; i < res - 1; i++)
        {
            newCurrNode1 = newCurrNode1->next;
        }
    }
    while(newCurrNode1!=NULL)
    {
        if(newCurrNode1==newCurrNode2)
        {
            return newCurrNode1;
        }
        newCurrNode1=newCurrNode1->next;
        newCurrNode2=newCurrNode2->next;
    }
    return NULL;

}


  
