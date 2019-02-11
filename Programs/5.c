/**********************************************************************
* FILENAME:        5.c

* AUTHOR: 20020298 | Rama Krishna | sabbella.krishna@wipro.com
* START DATE: 02/11/2019
* SUBMISSION DATE: 02/11/2019

**********************************************************************/

# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>

int main()
{
	pid_t pid;
	int status;
	pid=fork();
	if(pid==0)
	{
		printf("We are in the child process with PID=%d\n",getpid());
		//return 0;
		//exit(0);
	}
	if(pid!=0&&pid!=-1)
	{
		printf("We are in the parent process with PID=%d\n",getpid());
		wait(&status);
		printf("Exit Status is %d\n",WEXITSTATUS(status));
		if(WIFEXITED(status))
			printf("Normal termination\n");
		if(WIFSIGNALED(status))
			printf("Terminated by a signal\n");
	}
	return 0;
}


// If we don't return anything in child it exits with status 0
// If we use an exit it returns a status n%256
// if we use return , it always exits with status 0 for -256,256 and (256+n)%256 for negative values < -256 and (n-256)%256 for values > 256