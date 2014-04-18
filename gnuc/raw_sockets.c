/* filename: /mnt/sda6e/Bk2010-cl/cl-xx-2010cl/Lin/LinuxC/cxx/unpv12e_cl/raw_sockets.c
   date: 20130627-2000
   author&from: http://www.binarytides.com/raw-sockets-c-code-linux/
   update: getopt_long@lcmust@20130822-2045
*/
/*
  Raw TCP packets
  Silver Moon (m00n.silv3r@gmail.com)
*/
#include <stdio.h> //for printf
#include <string.h> //memset
#include <sys/socket.h> //for socket ofcourse
#include <stdlib.h> //for exit(0);
#include <errno.h> //For errno - the error number
#include <netinet/tcp.h> //Provides declarations for tcp header
#include <netinet/ip.h> //Provides declarations for ip header
#include <unistd.h>
#include <arpa/inet.h>  //for inet_addr/inet_pton/inet_ntop
#include <getopt.h>    //for getopt_long @20130822-2045
 
/* 
   96 bit (12 bytes) pseudo header needed for tcp header checksum calculation 
*/
struct pseudo_header
{
    u_int32_t source_address;
    u_int32_t dest_address;
    u_int8_t placeholder;
    u_int8_t protocol;
    u_int16_t tcp_length;
};
 
/*
  Generic checksum calculation function
*/
unsigned short csum(unsigned short *ptr, int nbytes) 
{
    register long sum;
    unsigned short oddbyte;
    register short answer;

    sum = 0;
    while (nbytes > 1) {
        sum += *ptr++;
        nbytes -= 2;
    }
    if (nbytes==1) {
        oddbyte = 0;
        *((u_char*)&oddbyte) = *(u_char*)ptr;
        sum += oddbyte;
    }
 
    sum = (sum >> 16) + (sum & 0xffff);
    sum = sum + (sum >> 16);
    answer = (short) ~ sum;  
   
    return(answer);
}

void print_help(void)
{
            printf("help message: -t source-ip\n"
                   "              -s target-ip\n");
}

int main (int argc, char *argv[])
{
	//argv[1] => -s( --source_ip )
	//argv[2] => -t( --test_ip )
    // source_port = 8944
    // target_port = 2345
    //暂时直接指定了源端口和目的端口号，
    //下一步将端口号从参数表中获取，'1.2.3.4:234'，就需要分割字符串来获取，分割符为:
    //lcmust@20130823-2211
    struct option St_long_option[] = {
        { "source_ip", required_argument, 0, 's'},
        { "target_ip", required_argument, 0, 't'},
        { "help", required_argument, 0, 'h'},
        { 0, no_argument, 0, 0}
    };

    /*
    struct option St_long_option_test[] = {
        { "afasfsa", 1, 0, 'a'},
        { "fjfijfi", 1, 0, 'c'}
    };
    */
    
    char *short_options = "s:t:h";
    char *source_ip = '\0';
    char *target_ip = '\0';
    
    while (1) {
        //int this_option_optind = optind ? optind : 1;
        int option_index = 0;
        int c;
        //int digit_optiond = 0;
        c = getopt_long(argc, argv, short_options,
                        St_long_option, &option_index);
        if (c == -1)
            break;
        
        switch (c) {
        case 0:
            printf("option %s", St_long_option[option_index].name);
            if (optarg)
                printf(" with arg %s", optarg);
            printf("\n");
            break;

        case 's':
            if (optarg[0] == '-') {
                printf("option -s(--source_ip) has *empty* arg\n");
                exit(-1);
            }
            printf("option -s(--source_ip) with value '%s'\n", optarg);
            source_ip = optarg;
            break;

        case 't':
            if (optarg[0] == '-') {
                printf("option -t(--target_ip) has *empty* arg\n");
                exit(-1);
            }
            printf("option -t(--target_ip) with value '%s'\n", optarg);
            target_ip = optarg;
            break;

        case ':':
            printf("option %c requires an argument\n", optopt);
            break;

        case 'h':
            print_help();
            /* printf("help message: -t source-ip\n" */
            /*        "              -s target-ip\n"); */
            exit(0);

        //default:
        case '?':
            printf("unkown option: %c\n", optopt);
            print_help();
            //break;
            exit(-2);
        }
    }

    printf("source_ip:%s\n", source_ip);
    printf("target_ip:%s\n", target_ip);
    //exit(0);


    //Create a raw socket
    int s = socket(PF_INET, SOCK_RAW, IPPROTO_TCP);
     
    if (s == -1) {
        //socket creation failed, may be because of non-root privileges
        perror("Failed to create socket");
        exit(1);
    }
     
    //Datagram to represent the packet
    char datagram[4096];
    char *data;
    char *pseudogram;

    //zero out the packet buffer
    memset(datagram, 0, 4096);
     
    //IP header
    struct iphdr *iph = (struct iphdr *)datagram;
     
    //TCP header
    struct tcphdr *tcph = (struct tcphdr *)(datagram + sizeof(struct ip));
    struct sockaddr_in sin;
    struct pseudo_header psh;
     
    //Data part
    data = datagram + sizeof(struct iphdr) + sizeof(struct tcphdr);
    strcpy(data, "ABCD0efgh0IJKLMNOPQRSTUVWXYZ");
     
    //some address resolution
    //strcpy(source_ip, "192.168.1.214");
	//strcpy(source_ip, argv[1]);
    sin.sin_family = AF_INET;
    sin.sin_port = htons(atoi("2345")); //target_port
    //sin.sin_addr.s_addr = inet_addr("192.168.1.119");
	if (inet_pton(AF_INET, target_ip, &sin.sin_addr.s_addr)) {
		printf("inet_pton(target_ip is sucssed!\n");
	} else {
        printf("%s(%d) has error\n", __FILE__, __LINE__);
		exit(-2);
	}
     
    //Fill in the IP Header
    iph->version = 4;  //ip0_4bit:0x4
    iph->ihl = 5;      //ip4_4bit:0x45
    iph->tos = 0;      //ip8_8bit:0x4500
    // 20(iphdr) + 20(tcphdr) + 26(data) = 66(0x42)
    //ip16_16bit:0x4500 0042
    iph->tot_len = sizeof(struct iphdr) + sizeof(struct tcphdr) + strlen(data);
    iph->id = htonl(0x8765432); //Id of this packet     //ip32_16bit:0x4500 0042 0876
    iph->frag_off = 0;   //ip48_16bit:0x4500 0042 0876 0000
    iph->ttl = 255;      //ip64_8bit:0x4500 0042 0876 0000 ff
    iph->protocol = IPPROTO_TCP;   //ip72_8bit:0x4500 0042 0876 0000 ff06
    //ip80_16bit:0x4500 0042 0876 0000 ff06 0000
    iph->check = 0;   //Set to 0 before calculating checksum
    //ip96_32bit:0x4500 0042 0876 0000 ff06 0000 c0a80102
    //iph->saddr = inet_addr(source_ip); //Spoof the source ip address
	inet_pton(AF_INET, source_ip, &iph->saddr);
	
    //ip128_32bit:0x4500 0042 0876 0000 ff06 0000 c0a80102 c0a80177
    iph->daddr = sin.sin_addr.s_addr;
    //iph->daddr = htonl(0xc0a80177);  // => 192.168.1.119
     
    //Ip checksum  00BE
    //iph->check = csum((unsigned short *)datagram, iph->tot_len);
    iph->check = csum((unsigned short *)datagram, iph->ihl << 2);
    //0x4500 0042 0876 0000 ff06 00be c0a80102 c0a80177
    
    int i;
    for (i = 0; i < 20; i++) {
        printf("%p\t %02X\n",
               (unsigned char *)datagram + i,
			   *((unsigned char *)datagram + i));
    }

    //TCP Header
    tcph->source = htons(atoi("8944"));
    tcph->dest = htons(atoi("2345"));
    tcph->seq = 0;
    tcph->ack_seq = 0;
    tcph->doff = 5;  //tcp header size
    tcph->fin = 0;
    tcph->syn = 1;
    tcph->rst = 0;
    tcph->psh = 0;
    tcph->ack = 0;
    tcph->urg = 0;
    tcph->window = htons(5840); /* maximum allowed window size */
    tcph->check = 0; //leave checksum 0 now, filled later by pseudo header
    tcph->urg_ptr = 0;
     
    //Now the TCP checksum
    //psh.source_address = inet_addr(source_ip);
    inet_pton(AF_INET, source_ip, &psh.source_address);
    psh.dest_address = sin.sin_addr.s_addr;
    psh.placeholder = 0;
    psh.protocol = IPPROTO_TCP;
    psh.tcp_length = htons(sizeof(struct tcphdr) + strlen(data));
     
    int psize = sizeof(struct pseudo_header) + sizeof(struct tcphdr) + strlen(data);
    pseudogram = malloc(psize);
     
    memcpy(pseudogram , (char*)&psh , sizeof(struct pseudo_header));
    memcpy(pseudogram + sizeof(struct pseudo_header), tcph , sizeof(struct tcphdr) + strlen(data));
     
    tcph->check = csum((unsigned short*)pseudogram, psize);
     
    //IP_HDRINCL to tell the kernel that headers are included in the packet
    int one = 1;
    const int *val = &one;
     
    if (setsockopt(s, IPPROTO_IP, IP_HDRINCL, val, sizeof(one)) < 0) {
        perror("Error setting IP_HDRINCL");
        exit(0);
    }
     
    //loop if you want to flood :)
    while (1) {
        //Send the packet
        if (sendto(s, datagram, iph->tot_len,
				   0, (struct sockaddr *) &sin,
				   sizeof (sin)) < 0) {
            perror("sendto failed");
        } else { //Data send successfully
            printf("Packet Send. Length : %d \n" , iph->tot_len);
        }
        sleep(2);
    }
     
    return 0;
}
 
//Complete
