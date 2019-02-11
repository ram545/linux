/**********************************************************************
* FILENAME:        9.c

* AUTHOR: 20020298 | Rama Krishna | sabbella.krishna@wipro.com
* START DATE: 02/11/2019
* SUBMISSION DATE: 02/11/2019

**********************************************************************/


# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <sys/types.h>

void sighandler(int signo)
{
	printf("PID %d received signal =%d\n",getpid(),signo);
	if(signo==2)
		printf("SIG INT Triggered\n");
	else if(signo==3)
		printf("SIG QUIT Triggered\n");
	else
		printf("SIG TERM Triggered\n");
}


main()
{
	int pid;
	signal(SIGINT,sighandler);
	signal(SIGTERM,sighandler);
	signal(SIGQUIT,sighandler);
	pid=fork();
	if(pid==0)
	{
		printf("The child process PID is %d\n",getpid());
		getchar();
	}
	if(pid!=0&&pid!=-1)
	{
		printf("The parent process PID is %d\n",getpid());
		kill(pid,SIGTERM);
		getchar();
	}
}