# include<stdio.h>
# include <signal.h>

main()

{
	printf("We are inside process %d\n",getpid());
	getchar();
	raise(SIGKILL);
}
