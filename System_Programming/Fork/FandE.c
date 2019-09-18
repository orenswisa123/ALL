#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>


int main()	
{
	pid_t pid;
	char* str;
	printf("enter program exe name: \n");
	scanf("%s" ,str);
	pid=fork();
	if(pid>0)
	{	
	wait(&pid);
	}
	else if(pid==0)
	{
	execv(str,NULL);
	}
	printf("its work\n");

	return 0;
}