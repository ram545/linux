# include <unistd.h>
# include <stdio.h>
# include <string.h>

# define Read 0
# define Write 1
char *message = "A child process writes into the pipe and its sibling reads from it\n";
main()
{
	int fd[2],bytesread;
	pid_t pid,pid1;
	char readmessage[100];
	pipe(fd);
	pid=fork();
	if(pid==0)
	{
		close(fd[Write]);
		bytesread=read(fd[Read],readmessage,100);
		printf("The child process read %d bytes from the parent process and the message is %s\n",bytesread,readmessage); 
		/*getchar();*/
	}
	if(pid!=0&&pid!=-1)
	{
		pid1=fork();
		if(pid1==0)
		{
			close(fd[Read]);
			write(fd[Write],message,strlen(message)+1);
		}

	}
	
}
	
