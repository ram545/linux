# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <stdlib.h>

main()

{
	int status=0;
	pid_t pid,pid1;
	pid=fork();
	if(pid==0)
	{
		printf("In child process\n");
		getchar();
		/*exit(-257);*/
	}
	if(pid!=0&&pid!=-1)
	{
		pid1=fork();
		if(pid1==0)
		{
			printf("The second child process\n");
			getchar();
		}
		if(pid1!=0 &&pid1!=-1)
		{

			printf("In the parent process\n");
			/*getchar();*/
			wait(&status);
			printf("%d\n",WEXITSTATUS(status));
			if(WIFEXITED(status))
				printf("Normal termination\n");
			if(WIFSIGNALED(status))
				printf("Terminated by a signal\n");
			/*getchar();*/
		}
	}
}
