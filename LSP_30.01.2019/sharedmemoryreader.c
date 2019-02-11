# include <sys/ipc.h>
# include <sys/shm.h>
# include <stdio.h>
# include <string.h>

main()
{
	int shmid;
	void *shmptr;
	key_t key;	
	key=ftok(".",1000);
	shmid=shmget(key,512,0);
	getchar();
	shmptr=shmat(shmid,0,0);
	printf("%s\n",shmptr);
	getchar();
	shmdt(shmptr);
	getchar();
	shmctl(shmid,IPC_RMID,0);
}	
