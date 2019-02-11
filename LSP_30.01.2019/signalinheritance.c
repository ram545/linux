# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <sys/types.h>

void sighandler(int signo)
{
	printf("PID %d received signal =%d\n",getpid(),signo);
}


main()
{
	int pid;
	signal(SIGINT,sighandler);
	signal(SIGCHLD,sighandler);
	pid=fork();
	if(pid==0)
	{
		printf("The child process PID is %d\n",getpid());
		execl("/bin/vi","vi","/root/Desktop/LSP_30.01.2019/source.txt",NULL);
		getchar();
	}
	if(pid!=0&&pid!=-1)
	{
		printf("The parent process PID is %d\n",getpid());
		getchar();
	}
}
