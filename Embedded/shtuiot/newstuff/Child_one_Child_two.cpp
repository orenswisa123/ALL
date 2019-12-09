#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

/*void child_one();
void child_two();*/

int main(int argc, char **argv, char **envp)
{
	int fds[2];
	pipe(fds);//we get 2 file descriptor from the kernel because its system call. 
	if (!fork())
	{
		//child_one();
		close(1);//1 its the fp we get from parent
		dup2(fds[1],1);//we write to the pipe because its [1], if it was [0] we read from the pipe
		close(fds[0]);
		return execlp("/bin/ls","/bin/ls","-l",NULL);
	}
	if (!fork())
	{
		//child_two();
		close(0);
		dup2(fds[0],0);
		close(fds[1]);
		return execlp("/usr/bin/wc","/usr/bin/wc","-l",NULL);//wc read from 0 in default but becuase we change 0 to fds[0] so its read from there.
	}
	//close ythe parents connection to the pipe
	close(fds[0]);
	close(fds[1]);
	/*this is the parent*/
	wait(NULL);
	wait(NULL);
	return EXIT_SUCCESS;
}
