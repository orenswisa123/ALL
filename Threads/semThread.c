#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#define NUM_OF_THREADS 100

sem_t mutex;
void* sort(void* arg)
{
    int local;
    local =*((int*)arg);
    sem_post(&mutex);
    printf("the number is: %d\n" , local );
}
int main()
{
    int status, i,j;
    pthread_t tid[NUM_OF_THREADS];
    sem_init(&mutex,0,1);
    for(i=0;i<NUM_OF_THREADS;i++)
    {
        sem_wait(&mutex);
        status=pthread_create(&tid[i],NULL,sort,&i);
    }
    for(j=0;j<NUM_OF_THREADS;j++)
    {
        pthread_join(tid[j],NULL);
    }
    sem_destroy(&mutex);
    return 1;
}