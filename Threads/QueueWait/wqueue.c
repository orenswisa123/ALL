#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
#include<semaphore.h>
#include<pthread.h>
#include"wqueue.h"
/*
struct Queue 
{ 
    int front,rear;
    int size; 
    unsigned int capacity; 
    sem_t empety;
    sem_t full;
    pthread_mutex_t lock;
    void** array; 
}; 
typedef struct  Queue Queue;
*/
Queue* createQueue(unsigned int capacity) 
{ 
    Queue* queue = (Queue*) malloc(sizeof(Queue)); 
    queue->capacity = capacity; 
    queue->array = malloc(queue->capacity * sizeof(void*)); 
    queue->front = 0;  
    queue->rear = 0; 
    queue->size=0;
    pthread_mutex_init(&(queue->lock),NULL);
    sem_init(&(queue->empty),0,capacity);
    sem_init(&(queue->full),0,0); 
    return queue; 
} 

int isFull(Queue* queue)
{
    return (queue->size == queue->capacity);
}

/* Queue is empty when size is 0 */
int isEmpty(Queue* queue)
{
    return (queue->size == 0);
}
void enqueue(Queue* queue, void* item) /*func to add item*/
{ 
    int p;
    p = *(int*)item;
    if (isFull(queue)) 
        return; 
    queue->rear = (queue->rear + 1)%(queue->capacity); 
    queue->array[queue->rear] = item; 
    queue->size = queue->size + 1; 
    printf("%d enqueued to queue\n", p); 
} 
void* dequeue(Queue* queue) /*func to remove*/
{ 
    void* item;; 
    if (isEmpty(queue)) 
        return (void*)INT_MIN; 
    item = (queue->array[queue->front]); 
    queue->front = (queue->front + 1)%queue->capacity; 
    queue->size = queue->size - 1; 
    return item; 
}

void* front(Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return (void*)INT_MIN; 
    return queue->array[queue->front]; 
} 

void* rear(Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return (void*)INT_MIN; 
    return queue->array[queue->rear]; 
} 