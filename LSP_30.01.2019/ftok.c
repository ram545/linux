# include <sys/ipc.h>
# include <stdio.h>

main()

{
	key_t key1,key2;
	key1=ftok("/root/Desktop/LSP_30.01.2019/source.txt",100);
	key2=ftok("/root/Desktop/LSP_30.01.2019/stat.c",5555);
	printf("key1=%d key2=%d\n",key1,key2);
}
