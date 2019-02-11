# include <stdio.h>
# include <signal.h>
# include <stdlib.h>

void sighandler(int signo)
{
	int status;
	printf("We are in the signal handler, received signal is %s\n",sys_siglist[signo]);
	wait(&status);
}

main()
{
	int pid;
	signal(SIGCHLD,sighandler);
	signal(SIGINT,sighandler);
	pid=fork();
	if(pid==0)
	{
		printf("We are in the child process with PID=%d\n",getpid());
		getchar();
		exit(0);
	}
	if(pid!=0&&pid!=-1)
	{
		printf("In the parent process with PID=%d\n",getpid());
		getchar();
	}
}

