#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h>

int main()
{
	char* msg="hey";
	char* msg2="bye";
	pid_t pid;
	int fd[2];
	pipe(fd);
	pid=fork();
	if(pid>0)
	{
		write(fd[1],msg,sizeof(msg));
		wait(&pid);
		read(fd[0],msg2,sizeof(msg));
		printf("%s\n" ,msg2);
	}
	else
	{
		read(fd[0],msg,sizeof(msg));
		printf("%s\n",msg);
		write(fd[1],msg,sizeof(msg2));
	}
	return 0;
}
