# include <stdio.h>
# include <sys/mman.h>
# include <fcntl.h>

main()

{
	int fd;
	void *mmptr;
	fd=open("mmapcontent.txt",O_RDONLY);
	mmptr=mmap(0,100,PROT_READ,MAP_SHARED,fd,0);
	printf("%s\n",mmptr);
	getchar();
	munmap(mmptr,100);
	getchar();
}
