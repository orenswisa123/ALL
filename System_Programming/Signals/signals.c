#include <signal.h>
#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>

void termination_handler(int signum,siginfo_t* a,void* v)
{
    write(1,"Ayy..\n",7);
    sleep(1);
}

int main (void)
{
    struct sigaction new_action;
    new_action.sa_flags = 1;
    new_action.sa_sigaction = termination_handler;
    sigaction(SIGINT,&new_action, NULL);
    while(1)
    {
        printf("In the loop\n");
        sleep(3);
    }
    return 0;
}