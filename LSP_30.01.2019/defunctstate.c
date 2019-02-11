# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
main()

{
	int status;
	pid_t pid;
	pid=fork();
	if(pid==0)
	{
		printf("In the child process with process id =%d\n",getpid());
		getchar();
		exit(0);

	}
	if(pid!=0&&pid!=-1)
	{
		printf("In the parent process with pid =%d\n",getpid());
		/*wait(&status);
		printf("Exit status no=%d\n",status);*/
		/*sleep(30);*/
	}
}
