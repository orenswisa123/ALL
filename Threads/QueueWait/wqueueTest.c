#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
#include"wqueue.h"
#define capacity 5
#define produceNum 2
#define consumNum 1
#define countMsg 3

void *producer (void *) ;
void *consumer(void *) ;

Queue* pcQueue;

int main()
{
    int i,j,m,n;
    pthread_t proThread[produceNum];
    pthread_t conThread[consumNum];
    pcQueue=createQueue(capacity);
    /*createProducers(pcQueue,proThread);*/
    for(i=0;i<produceNum-1;i++)
    {
        pthread_create(&proThread[i],NULL,producer,&i);
    }
    for(j=0;j<consumNum;j++)
    {
        pthread_create(&conThread[j],NULL,consumer,&j);
    }
    for(m=0;m<produceNum;m++)
    {
        pthread_join(proThread[m],NULL);
    }
    for(n=0;n<consumNum;n++)
    {
        pthread_join(conThread[n],NULL);
    }
    


}

void* producer(void *args){

    int i;
    int p;
    p = *(int*)args;
	for(i=0;i<countMsg;i++)
    {
		sem_wait(&(pcQueue->empty));
		pthread_mutex_lock(&(pcQueue->lock));
		enqueue(pcQueue,&p);  /* critical section */
		pthread_mutex_unlock(&(pcQueue->lock));
		sem_post(&(pcQueue->full));
	}
	return NULL;
}


void* consumer(void *args){
    int i;
    int p;
    p = *(int*)args;
	for(i=0;i<countMsg;i++)
    {
        sem_wait(&(pcQueue->full));
		pthread_mutex_lock(&(pcQueue->lock));
        /* critical section */
		printf("%d \n" ,*(int*)dequeue(pcQueue));
		pthread_mutex_unlock(&(pcQueue->lock));
		sem_post(&(pcQueue->empty));
	}

	return NULL;
}