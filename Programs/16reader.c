# include <sys/ipc.h>
# include <sys/shm.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

int main(int argc,char** argv)
{
	int shmid,fdwrite;
	char *fileName=argv[1];
	char *shmptr=(char)malloc(100*sizeof(char));
	key_t key;	
	fdwrite=open(filename,O_WRONLY|O_CREAT|O_TRUNC);
	key=ftok(".",1000);
	shmid=shmget(key,512,0);
	getchar();
	shmptr=shmat(shmid,0,0);
	write(fdwrite,shmptr,100);
	shmdt(shmptr);
	shmctl(shmid,IPC_RMID,0);
	close(fdwrite);
	return 0;
}	
