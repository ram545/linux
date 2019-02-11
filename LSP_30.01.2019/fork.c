# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>

void do_parent()
{
	printf("In the parent process with pid=%d\n",getpid());
	sleep(20);
	printf("Parent process terminated\n");
}
void do_child()
{
	printf("In the child process with pid=%d & ppid=%d\n",getpid(),getppid());
	sleep(10);
	printf("Child process terminated\n");
}


main()
{
	pid_t pid;
	pid=fork();
	switch(pid)
	{
		case -1:
			printf("The fork call failed\n");
			break;
		case 0:
			do_child();
			break;
		default:
			do_parent();
			break;
	}
	
}	
