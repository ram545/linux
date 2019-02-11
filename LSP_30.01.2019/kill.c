# include <stdio.h>
# include <signal.h>

main()
{
	int pid,status;
	pid=fork();
	if(pid==0)
	{
		printf("We are in the child process with PID=%d\n",getpid());
		getchar();
	}
	if(pid!=0&&pid!=-1)
	{
		printf("We are in the parent process with PID=%d\n",getpid());
		kill(getpid(),SIGKILL);
		wait(&status);
		getchar();
	}
}
