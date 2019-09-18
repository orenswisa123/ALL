#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>


int main()
{

	pid_t pid;
	pid=fork();
	if(pid>0)
	{
		printf("parent: %u \n" ,pid);
	}
	else
	{
		printf("child: %u \n" ,pid);
	}

	return 0;
}
