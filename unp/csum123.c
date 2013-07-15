/* filename: /mnt/sda6e/Bk2010-cl/cl-xx-2010cl/Lin/LinuxC/cxx/unpv12e_cl/csum123.c
   date: 20130720-1000
   author: chengl6500
*/
#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <stdint.h>

uint16_t csum(uint16_t *ptr, uint32_t nbytes) 
{
    register uint32_t sum;
    uint16_t oddbyte;
    register uint16_t answer;
 
    sum=0;
    while (nbytes > 1) {
        sum += *ptr++;
        nbytes -= 2;
    }
    if (nbytes == 1) {
        oddbyte = 0;
        *((uint8_t *)&oddbyte) = *(uint8_t *)ptr;
        sum += oddbyte;
    }
 
    sum = (sum >> 16) + (sum & 0xffff);
    sum = sum + (sum >> 16);
    answer = (uint16_t) ~ sum;
     
    return(answer);
}

uint32_t csum2(void *dp, uint16_t count)
{
	register uint32_t total = 0;
	register uint16_t n, *p, carries;

	n = count / 2;
	p = (uint16_t *)dp;
	while (n--)
		total += *p++;

	if (count & 1) {
		n = *(uint8_t *)p;
		total += n;
	}

	while ((carries = (uint16_t)(total >> 16)) != 0)
		total = (total & 0xffff) + carries;

    total = ~total;
    
	return ((uint16_t)total);
}

uint16_t ip_sum_calc(uint16_t buff[], uint16_t len_ip_header)
{
	uint16_t word16;
	uint32_t sum = 0;
	uint16_t i;
	uint16_t ip_header_words = len_ip_header / 2;
	for (i = 0; i < ip_header_words; i = i + 1) {
		word16 = (buff[i] & 0xff00) + (buff[i] & 0xff);
		sum += (uint32_t)word16;
	}
    if (len_ip_header % 2 == 1) {
        uint16_t ip_header_odd = 0;
        *(uint8_t *)&ip_header_odd = *(uint8_t *)&(buff[ip_header_words]);
        sum += ip_header_odd;
    }

    while (sum >> 16)
        sum = (sum & 0xffff) + (sum >> 16);

	sum = ~sum;
    
	return ((uint16_t)sum);
}

void print_chars_bits(uint16_t *tmp, uint32_t len_tmp)
{
    char resu[16];  //save the bits of char
    int i = 0;
    for (; i < len_tmp; i++) {
        printf("%p\t", (uint16_t *)tmp + i);
        printf("%04X\t", *((uint16_t *)tmp + i));

        //convert the char to bits, save to resu[]
        int j;
        for (j = 0; j < 16; j++) {
            resu[15 - j] = (tmp[i] >> j) & 1 ? '1':'0';
        }
        resu[16] = '\0';

        //print bits of resu[], every 4 bis print a empty
        int k;
        for (k = 0; k < 16; k++) {
            printf("%c", (char)(resu[k]));
            if ((k + 1) % 4 == 0) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void print_char1_bit8(uint8_t *tmp, uint32_t len)
{
    int i;
    char resu[8];
    while (len > 0) {
        printf("%p\t%02x\t", (uint8_t *)tmp + len, *((uint8_t *)tmp + len));
        for (i = 0; i < 8; i++) {
            resu[7 - i] = (tmp[len] >> i) & 1 ? '1' : '0';
        }
        resu[8] = '\0';

        //print bits of resu[], every 4 bis print a empty
        int k;
        for (k = 0; k < 8; k++) {
            printf("%c", (char)(resu[k]));
            if ((k + 1) % 4 == 0) {
                printf(" ");
            }
        }
        len -= 1;
        printf("\n");
    }
}

//4500 0170 5cf7 0000 0411 e73a c0a8 c0a8 efff fffa
int main(void)
{
    char ip_raw[4096];
    //memset(ip_raw, 0, 4096);
    bzero(ip_raw, 4096);
    struct iphdr *p_iph;
    p_iph = (struct iphdr *)ip_raw;
    p_iph->version = 4;
    p_iph->ihl = 5;
    p_iph->tos = 0;
    p_iph->tot_len = htons(0x0170);
    p_iph->id = htons(0x5cf7);
    p_iph->frag_off = 0;
    p_iph->ttl = 0x04;
    p_iph->protocol = 0x11;
    p_iph->check = 0;
    //p_iph->saddr = htonl(0xc0a8c0a8); // ||
    p_iph->saddr = inet_addr("192.168.192.168");
    //p_iph->saddr = 0xc0a8c0a8;
    //p_iph->daddr = htonl(0xeffffffa);  // ||
    p_iph->daddr = inet_addr("239.255.255.250");

    struct tcphdr *p_tcph;
    p_tcph = (struct tcphdr *)(ip_raw + sizeof(struct iphdr));
    p_tcph->source = htons(0x2346);
    p_tcph->dest = htons(0x9909);
    
    char *p_data;
    p_data = (char *)p_tcph + sizeof(struct tcphdr);
    char data[] = "ABCDEFGabcdefg";
    strncpy(p_data, data, sizeof(data));
    
    print_chars_bits((uint16_t *)ip_raw, 10);

    uint16_t resu6 = csum((uint16_t *)ip_raw, 20);
    printf("ip_raw csum(%x)\n", resu6);

    resu6 = csum2((uint16_t *)ip_raw, 20);
    printf("ip_raw csum2(%x)\n", resu6);
    
    resu6 = ip_sum_calc((uint16_t *)ip_raw, 20);
    printf("ip_raw ip_sum_calc(%x)\n", resu6);
    p_iph->check = resu6;
    //print_chars_bits((uint16_t *)ip_raw, 30);
    
    uint32_t *tmp1 = (uint32_t *)p_tcph;
    *tmp1 = 0x12349876;
    *(tmp1 + 1) = htonl(0x12345678);
    uint16_t *tmp2 = (uint16_t *)(tmp1 + 2);
    *(tmp2) = 0x7654;
    *(tmp2 + 1) = htons(0x7654); 
    //print_chars_bits((uint16_t *)ip_raw, 30);

    uint32_t tmp3;
    tmp3 = 0x456890;
    uint32_t tmp4 = 0x102345;
    printf("%p(tmp3)%x\t%p(tmp4)%x\n", &tmp3, tmp3, &tmp4, tmp4);
    //print_chars_bits((uint16_t *)&tmp3, 2);
    //print_chars_bits((uint16_t *)&tmp4, 2);
    //print_char1_bit8((uint8_t *)&tmp3, 6);
    print_char1_bit8(((uint8_t *)&ip_raw - 1), 21);
    printf("%p\n", &ip_raw);

    //print_bit16((uint16_t *)ip_raw, 12);
    printf("\n");
	return 0;

}
