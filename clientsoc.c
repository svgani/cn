#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<string.h>
#define SERV_TCP_PORT 6880
#define SERV_HOST_ADDR "127.0.0.1"
int main()
{
int sockfd;
struct sockaddr_in serv_addr,cli_addr;
char client[100],buf[1000];
int n;
serv_addr.sin_family=AF_INET;
serv_addr.sin_addr.s_addr=inet_addr(SERV_HOST_ADDR);
serv_addr.sin_port=htons(SERV_TCP_PORT);

if((sockfd=socket(AF_INET,SOCK_STREAM,0))<0)
	printf("client cant open stream socket\n");
else
	printf("client stream socket opened succesfully\n");
if(connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0)
	printf("client cant open to server\n");
else
	printf("client connected to server successfulluy\n");
printf("enter the filename to be displayed\n");
scanf("%s",client);
write(sockfd,client,strlen(client));
printf("\n file transferred succesfully to server\n");
n=read(sockfd,buf,1000);
if(n<0)
printf("\n error reading frm socket\n");
printf("client:displaying file contentof %s\n",client);
fputs(buf,stdout);
close(sockfd);
exit(0);
}


