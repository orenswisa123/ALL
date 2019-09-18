#include <stdio.h>
#include <pthread.h>
#include<unistd.h>
#define NUM_OF_THREADS 10000

int count=0;

void increment()
{
    int local;
    local =count;
    local++;
    count=local;
}
void* threadInc(void* arg)
{
    increment();

}

int main()
{
    int i;
    pthread_t thread[NUM_OF_THREADS];
    for(i=0;i<NUM_OF_THREADS;i++)
    {
       pthread_create(&thread[i],NULL,threadInc,NULL);
    }
    for(i=0;i<NUM_OF_THREADS;i++)
    {
        pthread_join(thread[i],NULL);
    }
    printf("%d\n" , count);
}