# include <unistd.h>
# include <stdio.h>
# define Read 0
# define Write 1


int main()
{
	int pipefd[2];
	pid_t pid1,pid2;
	char *argv1[] = {"cat","/usr/include/sysexits.h",NULL};
	char *argv2[]={"less",NULL};
	pipe(pipefd);
	pid1=fork();
	if(pid1==0)
	{
		dup2(pipefd[Write],STDOUT_FILENO);
		close(pipefd[Read]);
		execvp(argv1[0],argv1);
	}
	if(pid1!=-1&&pid1!=0)
	{
		pid2=fork();
		if(pid2==0)
		{
			dup2(pipefd[Read],STDIN_FILENO);
			close(pipefd[Write]);
			execvp(argv2[0],argv2);
		}
		if(pid2!=0&&pid2!=-1)
		{
			waitpid(pid1);
			waitpid(pid2);
		}
	}	
	return 0;
}
