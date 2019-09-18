#ifndef QUEUE_H
#define QUEUE_H

struct Queue 
{ 
    int front;
    int rear;
    int size; 
    unsigned int capacity; 
    sem_t empty;
    sem_t full;
    pthread_mutex_t lock;
    void** array; 
}; 

typedef struct  Queue Queue;
Queue* createQueue(unsigned int);
int isFull(Queue*);
int isEmpty(Queue*);
void enqueue(Queue* ,void*);
void* dequeue(Queue* );
void* front(Queue* );
void* rear(Queue* ); 

#endif

