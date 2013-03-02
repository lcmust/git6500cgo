#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/in_systm.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

char buffer2[100];

struct ip_header_test {
	unsigned int ip_hl:4;
	unsigned int ip_v:4;
	u_int8_t ip_tos;
	u_short ip_len;
	u_short ip_id;
	u_short ip_off;
	u_int8_t ip_ttl;
	u_int8_t ip_p;
	u_short ip_sum;
	struct in_addr ip_src, ip_dst;
	char a[0];
};

unsigned short check_sum(unsigned short *addr, int len)
{
	register int nleft = len;
	register int sum = 0;
	register short *w = addr;
	short answer = 0;
	while (nleft > 1) {
		printf("sum= %x w= %x *w= %x nleft= %d sum= %x\n", sum, w, *w, nleft, sum);
		sum += *w++;
		nleft -= 2;
	}

	if (nleft == 1) {
		*(unsigned char *)(&answer) = *(unsigned char *)w;
		sum += answer;
		printf("addr is event, the sum= %x\n", sum);
	}
	printf("sum(0)= %x\n", sum);
	sum = (sum >> 16) + (sum & 0xffff);
	printf("sum(>>)= %x\n", sum);
	sum += (sum >> 16);
	printf("sum(>>)= %x\n", sum);
	answer = ~sum;
	printf("answer(%%x)= %x sum(%%x)= %x\n", answer &0xffff, sum);
	//printf("answer(%%u)= %u sum(%%u)= %u\n", answer, sum);
	return answer;
}

void send_tcp(int sockfd, struct sockaddr_in *addr)
{
	char buffer[100];
	struct ip *ip;
	struct tcphdr *tcp;
	int head_len;

	head_len = sizeof(struct ip) + sizeof(struct tcphdr);
	printf("head_len= %d %d\n", head_len, sizeof(short));

	bzero(buffer, 100);

	//padding ip
	ip = (struct ip *)buffer;
	ip->ip_v = IPVERSION;
	ip->ip_hl = sizeof(struct ip) >> 2;
	ip->ip_tos = 0;
	ip->ip_len = htons(head_len);
	ip->ip_id = 0;
	ip->ip_off = 0;
	ip->ip_ttl = MAXTTL;
	ip->ip_p = IPPROTO_TCP;
	ip->ip_sum = 0; //(ip_sum: d0bb)
	ip->ip_sum = check_sum((unsigned short *)ip, sizeof(struct ip));
	//printf("after check_sum$ ip->ip_sum= %x\n", ip->ip_sum);

	ip->ip_dst = addr->sin_addr;

	//padding tcp
	tcp = (struct tcphdr *)(buffer + sizeof(struct ip));
	tcp->source = htons(10000);
	tcp->dest = addr->sin_port;
	tcp->seq = random();
	tcp->ack_seq = 0;
	tcp->doff = 5;
	tcp->syn = 1;
	//tcp->ack = 1;
	tcp->check = 0;
	tcp->window = htons(32972);

	//tcp->check = htons(0x302c); //93af  //(check: 9cb3)
	tcp->check = check_sum((unsigned short *)tcp, sizeof(struct tcphdr));
	//printf("after check_sum$ tcp->check= %x, = %d, = %u\n", tcp->check, tcp->check, tcp->check);

	ip->ip_src.s_addr = inet_addr("192.168.1.1");

	int i;
	for (i = 1; i < 2; i++) {
		//ip->ip_src.s_addr = random();
		//ip->ip_src.s_addr = inet_addr("192.168.1.1");
		//printf("ip src= %s\n", inet_ntoa(ip->ip_src));

		//tcp->check = check_sum((unsigned short *)tcp, sizeof(struct tcphdr));
		//tcp->check = 0x2e57;
		sendto(socket, buffer, head_len, 0, (struct sockaddr *)addr, sizeof(struct sockaddr_in));
		if (i % 100 == 0) {
			tcp->source = htons(ntohs(tcp->source) + 1);
			tcp->check = htons(ntohs(tcp->check) - 1);
		}

		if (i == 3000000) {
			tcp->source = htons(10000);
			tcp->check = htons(0x93af);
		}
		//sendto(sockfd, buffer2, 60, 0, (struct sockaddr *)addr, sizeof(struct sockaddr_in));
		//printf("new length= %d\n", strlen(buffer2));
	}
}

int main(int argc, char *argv[])
{
	int a1;
	a1 = 293810;
	short a2;
	a2 = 293810;
	printf("a1= %d a2= %d\n", a1, a2);
	printf("a1= %x a2= %x\n", a1, a2);
	printf("~a2= %x ~a2= %d size(a1)= %d size(a2)= %d\n", ~a2, ~a2, sizeof(a1), sizeof(a2));

	int sockfd;
	struct sockaddr_in addr;
	struct hostent *host;
	int on = 1;
	bzero(&addr, sizeof(struct sockaddr_in));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(25555);
	addr.sin_addr.s_addr = inet_addr("192.168.1.119");
	/*if (inet_aton(argv[1], &addr.sin_addr) == 0) {
	  host = gethostbyname(argv[1]);
	  if (host == NULL) {
	  //fprintf(stderr, "Host name ERROR:%s\n\a", hstrerror(h_errno));
	  exit(1);
	  }
	  addr.sin_addr = *(struct in_addr *)(host->h_addr_list[0]);
	  }
	*/

	sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
	if (sockfd < 0) {
		fprintf(stderr, "Socket ERROR:%s\n\a", strerror(errno));
		exit(1);
	}

	setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &on, sizeof(on));
	setuid(getpid());
	send_tcp(sockfd, &addr);

	exit(0);
}
