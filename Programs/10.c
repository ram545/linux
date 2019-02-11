/**********************************************************************
* FILENAME:        10.c

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
}


main()
{
	int status=0;
	pid_t pid,pid1;
	signal(SIGINT,sighandler);
	pid=fork();
	if(pid==0)
	{
		printf("In child process\n");
		while(1){
			printf("Child1\n");
		}
	}
	if(pid!=0&&pid!=-1)
	{
		pid1=fork();
		if(pid1==0)
		{
			printf("The second child process, pid1=%d\n",getpid());
			while(1){
				printf("Child2\n");
			}
		}
		if(pid1!=0 &&pid1!=-1)
		{
			printf("In the parent process\n");
			kill(pid,SIGINT);
			kill(pid1,SIGINT);
			//kill(getpid(),SIGINT);
		}
	}
}

//When process send SIGINT to itself, child become orphan
//When process send SIGINT to child, process executes properly