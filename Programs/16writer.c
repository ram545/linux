# include <sys/ipc.h>
# include <sys/shm.h>
# include <stdio.h>
# include <string.h>


int main(int argc,char** argv)
{
	int shmid,fdread,bytesRead;
	key_t key;
	char *filename;
	char *shmptr=(char)malloc(100*sizeof(char));
	filename=argv[1];
	key=ftok(".",1000);
	fdread=open(filename,O_RDONLY);
	shmid=shmget(key,512,IPC_CREAT|0644);
	printf("The shared memory segment with id %d is created\n",shmid);
	shmptr=(char*)shmat(shmid,0,0);
	read(fdread,shmptr,100);
	printf("%s\n",shmptr);
	shmdt(shmptr);
	close(fdread);
	return 0;
}
