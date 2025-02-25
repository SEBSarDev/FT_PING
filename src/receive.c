#include "../inc/ft_ping.h"

extern struct info_time resume;

int get_headers(char *recbuf, struct icmphdr **icmp, struct timeval **time , struct icmphdr **icmp_ret)
{
	int ret;

	ret = 0;
	*icmp = (struct icmphdr*)(recbuf + sizeof(struct iphdr));
	*icmp_ret = (struct icmphdr*)(recbuf + sizeof(struct iphdr));
	*time = (struct timeval *)(recbuf + sizeof(struct iphdr)+ sizeof(struct icmphdr));
	if ((*icmp)->type != 0)
	{
		*icmp = (struct icmphdr*)(recbuf + sizeof(struct iphdr) * 2 + sizeof(struct icmphdr));
		*icmp_ret = (struct icmphdr*)(recbuf + sizeof(struct iphdr));
		*time = (struct timeval *)(recbuf + sizeof(struct iphdr)+ sizeof(struct icmphdr));
		ret = 1;
	}
	if ((*icmp)->un.echo.id != getpid())
		return (-1);
	return (ret);
}

struct timeval *store_rtt(struct timeval *send_at, struct timeval *received_at)
{
	struct rtt_list *rtt = NULL;
	struct rtt_list *stock;
	rtt = malloc(sizeof(struct rtt_list));
	if (!rtt)
	{
		error_msg(0, strerror(errno));
		return (NULL);
	}
  	timersub(received_at, send_at, &rtt->rtt);
	rtt->millis = (((float)rtt->rtt.tv_sec * (float)1000) + ((float)rtt->rtt.tv_usec / (float)1000));
	rtt->prev = NULL;
	rtt->next = NULL;
	stock = resume.all_rtt;
	if (resume.all_rtt)
	{
		while(resume.all_rtt->next)
			resume.all_rtt = resume.all_rtt->next;
		rtt->prev = resume.all_rtt;
		resume.all_rtt->next = rtt;
		resume.all_rtt = stock;
	}
	else
		resume.all_rtt = rtt;
	return &rtt->rtt;
}

int parse_rec(char *recbuf, int recv, struct dest_info *dest, struct timeval *received_at)
{
    int ret;
	struct icmphdr *stock_icmp;
	struct timeval *send_at = NULL;
	struct icmphdr *stock_icmp_ret;
    struct timeval *time_to;

	ret = get_headers(recbuf, &stock_icmp, &send_at, &stock_icmp_ret);
    if (ret == -1)
		return (0);
	if (ret == 0)
    {
		time_to = store_rtt(send_at, received_at);
        if (time_to == NULL)
			return (-1);
		resume.received++;
        print_infos_source_reply(recv, (struct iphdr*)(recbuf), dest);
        print_infos_header_reply(stock_icmp, (struct iphdr*)(recbuf), time_to);
    }
	if (ret == 1)
    {
        resume.errors++;
        print_bad_response((struct iphdr*)(recbuf), stock_icmp, stock_icmp_ret);
    }
    return (0);
}
int receive(int sockfd, struct dest_info *dest)
{
	char recbuf[(sizeof(struct iphdr) + sizeof(struct icmphdr))*2 + 57];
	struct timeval received_at;
	int recv;

	recv = recvfrom(sockfd, recbuf, sizeof(recbuf), MSG_DONTWAIT, NULL, NULL);
	if (recv < 0)
	{
		if (errno == EAGAIN || errno == EWOULDBLOCK)
			return (0);
		return (error_msg(0, strerror(errno)));
	}
    if (gettimeofday(&received_at, NULL) < 0)
		return (error_msg(0, strerror(errno)));
    parse_rec(recbuf, recv, dest, &received_at);
	return(0);
}