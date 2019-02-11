# include <stdio.h>
# include <signal.h>

void sighan(int signo)
{
	printf("SIGALRAM handler invoked\n");
}

main()
{
	int x=0;
	signal(SIGALRM,sighan);
	printf("Setting an alarm \n");
	x=alarm(10);
	printf("The alarm return value is %d\n",x);
	x=alarm(20);
	printf("The alarm return calue is %d\n",x);
	pause();
	printf("Pause is a blocking call and this statement is not printed, till the alarm is raised and the handler returns\n");
}
