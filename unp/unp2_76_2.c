#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAXLINE 100

int print_hostent(struct hostent *ent)
{
    if (ent == NULL) {
        printf("the argv(ent) is NULL\n");
        return -1;
    }
    printf("ent->name:%s\n", ent->h_name);
    printf("ent->alias:%s\n",  *(ent->h_aliases));
    char **tmp = ent->h_addr_list;
    while (*(tmp)) {
        printf("ent->addr:%s\n",  inet_ntoa(*((struct in_addr *)*tmp)));
        printf("ent_addr(inet):%x\n", (*((unsigned int *)(ent->h_addr_list[0]))));
        sleep(1);
        tmp = tmp + 1;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    ssize_t abc;
    unsigned int session_no = 0;
    struct hostent *qq_ent;
    qq_ent = NULL;
    if (argv[1] != NULL) {
        if ((qq_ent = gethostbyname(argv[1])) == NULL) {
            printf("gethostbyname(%s) run has a error!\n", argv[1]);
            //exit(-1);
        }
    }

    if (! qq_ent) {
        if ((qq_ent = gethostbyname("www.qq.com")) == NULL) {
            printf("gethostbyname(www.qq.com) run has a error!\n");
            //exit(-1);
        }
    }

    print_hostent(qq_ent);
    struct in_addr addr1;
    if (argv[1]) {
        if (inet_aton(argv[1], &addr1)) {
            printf("(argv[1])(inet_aton) => %x\n", addr1.s_addr);
        }
    }

    printf("Server is begin....\n");
    int server_len, client_len;
    time_t ticks;
    int listenfd, connfd;
    struct sockaddr_in server_addr, client_addr;
    char buff[MAXLINE];
    bzero(&server_addr, sizeof(server_addr));
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    if (argv[1]) {
        if (! inet_aton(argv[1], NULL)) {
            printf("the argv[1] is wrong, must be '1.1.1.1 => 255.255.255.255'!\n");
            //exit(-1);
        }
        if (! inet_aton(argv[1], &(server_addr.sin_addr))) {
            printf("inet_aton run has a error!\n");
            //exit(-1);
        }
        if (! inet_pton(AF_INET, argv[1], &server_addr.sin_addr)) {
            printf("inet_pton run has a error!\n");
            exit(-2);
        }
    } else {
        server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    }
    //server_addr.sin_addr.s_addr = inet_aton("0.0.0.0");
    if (argv[2]) {
        server_addr.sin_port = htons(atoi(argv[2]));
    } else {
        server_addr.sin_port = htons(8001);
    }

    server_len = sizeof(server_addr);
    if (bind(listenfd, (struct sockaddr *)&server_addr, server_len)) {
        printf("bind  run has a error!\n"
               "may be argv[1] is not your server ip address\n"
               "OR argv[2](port) < 1024\n");
        exit(-1);
    }
        
    listen(listenfd, 128);

    for (; ;) {
        client_len = sizeof(client_addr);
        connfd = accept(listenfd, (struct sockaddr *)&client_addr, (socklen_t *)&client_len);
        session_no += 1;
        printf("client_addr(net):%x (addr):%s(session:%d)\n",
               client_addr.sin_addr.s_addr,
               inet_ntoa(client_addr.sin_addr), session_no);
        ticks = time(NULL);
        snprintf(buff, sizeof(buff), "%24s\r\n", ctime(&ticks));
        write(connfd, buff, strlen(buff));
        close(connfd);

        printf("\n");
        //exit(0);
    }
}
