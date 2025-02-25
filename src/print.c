#include "../inc/ft_ping.h"

extern struct info_time resume;

void print_sock_info(struct dest_info *dest, int sockfd)
{
		printf("ping: sock4.fd: %d, (socktype: SOCK_RAW), hints.ai_family: AF_INET\n\n", sockfd);
		printf("ai->ai_family: AF_INET, ai->ai_canonname: '%s'\n", dest->hostname);
}

void print_start(struct dest_info *dest)
{
    size_t size;

    size = sizeof(struct iphdr) + sizeof(struct icmphdr) + 56;
	printf("PING %s (%s) 56(%lu) bytes of data\n", dest->hostname, dest->ipv4, size);
}

void print_infos_source_reply(int recv, struct iphdr *ip, struct dest_info *dest)
{
    struct in_addr source;
	source.s_addr = ip->saddr;
	char *saddr = inet_ntoa(source);
	
    printf("%lu bytes from %s (%s): ", recv - sizeof(struct iphdr), dest->hostname, saddr);
}

void print_infos_header_reply(struct icmphdr *stock_icmp, struct iphdr *ip, struct timeval *time_to)
{
    float millisecond;

    millisecond = calcul_millisecond(*time_to);
	printf("icmp_seq=%d ", stock_icmp->un.echo.sequence);
    if (resume.v)
        printf("ident=%d ", stock_icmp->un.echo.id);
    printf("ttl=%d ", ip->ttl);
    if (millisecond < 10)
		printf("temps=%.2f ms\n", millisecond);
    else
        printf("temps=%.1f ms\n", millisecond);
    }

void print_bad_response(struct iphdr *ip, struct icmphdr *stock_icmp, struct icmphdr *stock_icmp_ret)
{
    struct in_addr source;
	source.s_addr = ip->saddr;
	char *saddr = inet_ntoa(source);

    printf("From %s (%s): icmp_seq=%d ", saddr, saddr, stock_icmp->un.echo.sequence);
    print_type_error(stock_icmp_ret->type, stock_icmp_ret->code);
	if (resume.v)
		printf("type=%d code=%d", stock_icmp_ret->type, stock_icmp_ret->code);
	printf("\n");
}
