# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
/*# include <sys/types.h>*/

main()
{
int pid,sid;
FILE *fp=NULL;
pid=fork();
getchar();
if(pid!=0&&pid!=-1)
{
	exit(0);
}
umask(0);
setsid();
chdir("/");
close(STDIN_FILENO);
close(STDOUT_FILENO);
close(STDERR_FILENO);
fp=fopen("/log.txt","w+");
while(1)
{
	sleep(1);
	fprintf(fp,"Logging info...\n");
	fflush(fp);
}
}

