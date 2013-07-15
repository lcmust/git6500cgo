#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int socket_s1;
	struct sockaddr_in serveraddr;
    struct sockaddr_in clientaddr;
    int func_status;
	int conn_status;
    memset(&serveraddr, 0, sizeof(serveraddr));
    memset(&clientaddr, 0, sizeof(clientaddr));
    
    func_status = 0;
	if (argv[1]) {
        func_status = inet_aton(argv[1], &(serveraddr.sin_addr));
    } else {
        func_status = inet_aton("127.0.0.1", &(serveraddr.sin_addr));
    }
    if (!func_status) {
        printf("inet_aton at (%s) of (%s)\n", __LINE__, __FILE__);
        exit(-1);
    }

    if (0) {
        serveraddr.sin_port = htons(atoi(argv[2]));
    } else {
        serveraddr.sin_port = htons(1234);
    }
    if (!serveraddr.sin_port) {
        printf("inet_aton at (%s) of (%s)\n", __LINE__, __FILE__);
        exit(-1);
    }
	
    socket_s1 = socket(AF_INET, SOCK_STREAM, 0);
    conn_status = connect(socket_s1,  (struct sockaddr *)&serveraddr, sizeof(serveraddr));

    char server_ip[16];
    char client_ip[16];
    char *p_server_ip;
    char *p_client_ip;
    p_server_ip = inet_ntoa(serveraddr.sin_addr);
    memcpy(server_ip, inet_ntoa(serveraddr.sin_addr), sizeof(inet_ntoa(serveraddr.sin_addr)));
    printf("server_ip = %s\n", server_ip);
    p_server_ip = inet_ntoa(clientaddr.sin_addr);
    memcpy(server_ip, inet_ntoa(clientaddr.sin_addr), sizeof(inet_ntoa(clientaddr.sin_addr)));
    //memcpy(client_ip, p_server_ip, sizeof(p_server_ip));
    printf("client_ip = %s\n", client_ip);

    //printf("serveraddr%%s = %s\n", server_ip);
    printf("serveraddr%%x = %x\n", serveraddr.sin_addr);

    printf("socket_s1 = %d\n", socket_s1);

    if (argv[1]) {
        printf("argv[1] = %s\n", argv[1]);
        printf("argv[1] = %s\n", inet_ntoa(serveraddr.sin_addr));
    }
    if (argv[2]) {
        printf("argv[2] = %s\n", argv[2]);
    }
    
    return 0;
}
