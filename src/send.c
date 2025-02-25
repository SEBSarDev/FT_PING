#include "../inc/ft_ping.h"

extern struct info_time resume;

int fill_icmp(struct icmphdr *icmp, int *i, char *buffer)
{
	unsigned short sum;
	struct timeval *send_at;
	send_at = (struct timeval *)(buffer + sizeof(struct icmphdr));

	if (gettimeofday(send_at, NULL) < 0)
		return (error_msg(0, strerror(errno)));
	(*i)++;
	icmp->type = 8;
	icmp->code = 0;
	icmp->checksum = 0;
	icmp->un.echo.id = getpid();
	icmp->un.echo.sequence = *i;
	sum = checksum((void *)icmp, sizeof(struct icmphdr) + 56);
	icmp->checksum = sum;
	return 0;
}

int send_icmp(struct sockaddr_in *dest_addr, int sockfd, int *i)
{
	char buffer[sizeof(struct icmphdr) + 56];
	struct icmphdr *icmp;
    int ret;

	memset(&buffer, 0, sizeof(struct icmphdr) + 56);
    icmp = (struct icmphdr*)buffer;
	fill_icmp(icmp, i, buffer);
	ret = sendto(sockfd, buffer, sizeof(buffer), 0, \
        (struct sockaddr *)dest_addr, sizeof(struct sockaddr_in));
	if (ret < 0)
	{
		if (errno == EACCES)
			return (error_msg(BROADCAST, NULL));
		error_msg(0, strerror(errno));
	}
	resume.nb++;
	resume.ready = 0;
    return (0);
}