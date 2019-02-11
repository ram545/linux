# include <sys/ipc.h>
# include <sys/shm.h>
# include <stdio.h>
# include <string.h>
main()
{
	int shmid;
	key_t key;
	void *shmptr;
	key=ftok(".",1000);
	shmid=shmget(key,512,IPC_CREAT|0644);
	printf("The shared memory segment with id %d is created\n",shmid);
	getchar();
	shmptr=shmat(shmid,0,0);
	strcpy((char*)shmptr,"Hello world- the first entry into shared memory\0");
	printf("%s\n",shmptr);
	getchar();
	shmdt(shmptr);
	getchar();
}
