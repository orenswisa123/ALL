#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <pthread.h>
#include <iostream>
#include <exception>
//just declarition to keep compilar happy
void *a_c_function(void *some_data);

class Thread
{
public:
    Thread() {}
    virtual ~Thread() {}
    void start()
    {
        //here we call pthread_create
        int return_value;
        return_value = pthread_create(&m_id, NULL, a_c_function, this);
        if (return_value == 0)
        {
            throw new Exception();
        }
    }
    void join()
    {
        int return_value = pthread_join(m_id, NULL);
        if (return_value != 0)
        {
            throw new Exception();
        }
    }
    void run() = 0;

private:
    pthread_t m_id;
};
void *a_c_function(void *some_data)
{
    Thread *t = (Thread *)some_data;
    t->run();
}
//now this is a user...
class InThread : public Thread
{
    void run()
    {
        std::cout << "hello world" << endl;
    };

#endif // !MYTHREAD_H