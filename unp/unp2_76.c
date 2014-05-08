#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXLINE 100

int main(void)
{
	int server_len, client_len;
	time_t ticks;
	int listenfd, connfd;
	struct sockaddr_in server_addr, client_addr;
	char buff[MAXLINE];
	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	//server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	//printf("\n%s\n", inet_ntoa(server_addr.sin_addr));
	server_addr.sin_port = htons(8001);
	server_len = sizeof(server_addr);

	if (gethostname(buff, strlen(buff))) {
		printf("server' hostname: %s\n", buff);
	}
	printf("\n%d\n",       8001);
	printf("\n%d\n", htons(8001));
	printf("\n%d\n", htons(htons(8001)));

	bind(listenfd, (struct sockaddr *)&server_addr, server_len);
	listen(listenfd, 5);

	for (; ;) {
		client_len = sizeof(client_addr);
		connfd = accept(listenfd,(struct sockaddr *) &client_addr, (socklen_t *)&client_len);
		/*		printf("connection from %s, port %d\n",
				inet_ntop(AF_INET, &client_addr.sin_addr, buff, sizeof(buff)), ntohs(client_addr.sin_port));
		*/
		ticks = time(NULL);
		snprintf(buff, sizeof(buff), "%24s\r\n", ctime(&ticks));
		write(connfd, buff, strlen(buff));
		close(connfd);

		printf("\n");
		exit(0);
	}
}
