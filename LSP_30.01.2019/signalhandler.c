# include <signal.h>
# include <stdio.h>

void sighandler(int signo)
{
	printf("We are in the signal handler module. Received signal is %s\n",sys_siglist[signo]);

}


main()
{
	signal(SIGINT,sighandler);
	getchar();
}
