# include <unistd.h>
# include <sys/types.h>
# include <stdio.h>
main()
{
	pid_t pid;
	pid=fork();
	if(pid==0)
	{
		execl("/bin/vi","vi","/root/Desktop/LSP_30.01.2019/source.txt",NULL);
	}
	if(pid!=0&&pid!=-1)
	{
		printf("In the parent process\n");
		getchar();
	}
}
