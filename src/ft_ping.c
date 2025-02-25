#include "../inc/ft_ping.h"

struct info_time resume;

void intHandler(int sig) { 
    if (sig == SIGINT)
		resume.loop = 0;
	if (sig == SIGQUIT)
		resume.print = 1; //ou direct print
	if (sig == SIGALRM)
		resume.ready = 1;
}

int get_ip(int n, char **argv, struct dest_info *dest, int sockfd)
{
	struct addrinfo hints;
	void *ptr;
	char str[16];

	memset(&hints, 0, sizeof (hints));
	dest->hostname = NULL;
	dest->ipv4 = NULL;
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_RAW;
	hints.ai_protocol = IPPROTO_ICMP;
	if (getaddrinfo(argv[n], NULL, &hints, &dest->addr))
		return(error_msg(ERR_DNS, NULL));
	ptr = &((struct sockaddr_in *) dest->addr->ai_addr)->sin_addr;
	if (!inet_ntop(AF_INET, ptr, str, 16)) 
		return (error_msg(FCTN_FAIL, "inet_ntop()"));
	dest->hostname = ft_strdup(argv[n]);
	dest->ipv4 = ft_strdup(str);
	if (resume.v)
		print_sock_info(dest, sockfd);
	return(0);
}

int run_ping(struct dest_info *dest, int sockfd)
{
	struct sockaddr_in dest_addr;
	int i = 0;

	memset(&dest_addr, 0, sizeof(dest_addr));
	dest_addr.sin_family = AF_INET;
	dest_addr.sin_addr.s_addr = inet_addr(dest->ipv4);
	print_start(dest);
	while (resume.loop)
	{
		if (resume.ready)
		{
			if (send_icmp(&dest_addr, sockfd, &i) < 0)
				return (-1);
			alarm(1);
		}
		if (resume.print)
			print_inter_stat();
		if (receive(sockfd, dest) < 0)
			return (-1);
	}
	return 0;
}

int main(int argc, char **argv)
{
	int args;
	struct dest_info dest;
	struct timeval final;
	int sockfd;

	if (geteuid())
		return (error_msg(0, "Please run program with sudo privileges\n"));
	if (init_resume(&dest) == -1)
		return (-1);
	if ((args = get_args(argc, argv)) == -1)
		    return(1);
	sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (sockfd < 0)
		return(error_msg(FCTN_FAIL, "socket()"));
	if (get_ip(args, argv, &dest, sockfd) < 0)
	{
		free_all(&dest, sockfd);
		return (2);
	}
	signal(SIGINT, intHandler);
	signal(SIGQUIT, intHandler);
	signal(SIGALRM, intHandler);
	run_ping(&dest, sockfd);
    if (gettimeofday(&final, NULL) < 0)
		return (error_msg(0, strerror(errno)));
	print_final_stat(dest, &final);
	free_all(&dest, sockfd);
	return (0);
}
