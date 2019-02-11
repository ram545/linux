# include <stdio.h>
# include <sys/socket.h>
# include <netinet/in.h>
# define SERVER_ADDR "127.0.0.1" 

void transact_with_client(int sock)
{
	char buf[100];
	int n;
	while((n=recv(sock,buf,sizeof(buf),0))>0)
		send(sock,buf,n,0);
}



main(int argc,char *argv[])
{
	int socfd,port,size,csd;
	struct sockaddr_in server,client;
	socfd=socket(AF_INET,SOCK_STREAM,0);
	port=atoi(argv[1]);
	server.sin_family=AF_INET;
	server.sin_addr.s_addr=inet_addr(SERVER_ADDR);
	server.sin_port=htons(port);
	bind(socfd,(struct sockaddr*)&server,sizeof(server));
	listen(socfd,5);	
	while(1)
	{
		size=sizeof(client);
		csd=accept(socfd,(struct sockaddr*)&client,&size);
		transact_with_client(csd);
		close(csd);
	}
	close(socfd);
}
