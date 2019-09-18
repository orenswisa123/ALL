#include <stdio.h>
#include <pthread.h>
#include<unistd.h>

void* thread1(void* arg)
{
    int count;
    printf("thread 1 got : %d \n ", *((int*)arg));
    for(count=0;count<5;count++)
    {
        printf(">>>>>>>>> 1: count %d \n" , count);
        sleep(3);
    }

}
void * thread2(void* arg)
{
    int count;
    for(count=0;count<5;count++)
    {
        printf("            >>>>>>>>>> 2 : count %d \n",count);
        sleep(1);
    }
}
int main()
{
    int status;
    pthread_t tid1,tid2;
    int param1 = 11;
    int param2 = 12;
    status = pthread_create(&tid1,NULL,thread1,&param1);
    status = pthread_create(&tid2,NULL,thread2,&param2);
    pthread_join(tid1,NULL);
  /*  pthread_join(tid2,NULL);*/
    
}