#include "../inc/ft_ping.h"

extern struct info_time resume;

void free_all(struct dest_info *dest, int sockfd)
{
	struct rtt_list *temp;

	if (dest->hostname)
		free(dest->hostname);
	if (dest->ipv4)
		free(dest->ipv4);
	if (sockfd)
		close(sockfd);
	if (dest->addr)
		freeaddrinfo(dest->addr);
	if (resume.all_rtt)
	{
		temp = resume.all_rtt;
		while (resume.all_rtt)
		{
			temp = resume.all_rtt->next;
			free(resume.all_rtt);
			resume.all_rtt = temp;
		}
	}
}

unsigned short checksum(void *addr, size_t count)
{
	unsigned short *temp = addr;
    unsigned int sum = 0;
	unsigned short res;

    while( count > 1 )  {
        sum += * (unsigned short *) temp++;
        count -= 2;
    }

    if ( count > 0 )
        sum += * (unsigned char *) temp;

    while (sum>>16)
        sum = (sum & 0xffff) + (sum >> 16);

    res = (unsigned short) ~sum;
	return res;
}


int init_resume(struct dest_info *dest)
{
	resume.loop = 1;
	resume.print = 0;
	resume.nb = 0;
	resume.v = 0;
	resume.ready = 1;
    resume.errors = 0;
	resume.received = 0;
	if (gettimeofday(&resume.start, NULL) < 0)
		return (error_msg(0, strerror(errno)));
	resume.min.tv_sec = -1;
	resume.min.tv_usec = -1;
	resume.moy = -1;
	resume.max.tv_sec = -1;
	resume.max.tv_usec = -1;
	resume.mdev = -1;
	resume.all_rtt = NULL;
	dest->addr = NULL;
	return (0);
}

int get_args(int argc, char **argv)
{
	if (argc < 2 || argc > 3)
		return (error_msg(USAGE, NULL));
	if (!ft_strcmp(argv[1], "-?")
		|| (argv[2] && (!ft_strcmp(argv[2], "-?"))))
		return (error_msg(USAGE, NULL));
	if (argc == 3)
	{
		if (!ft_strcmp(argv[1], "-v"))
		{
			resume.v = 1;
			return(2);
		}
		else if (!ft_strcmp(argv[2], "-v"))
		{
			resume.v = 1;
			return (1);
		}
		else
			return (error_msg(USAGE, NULL));
	}
	return (1);
}

float calcul_millisecond(struct timeval my_time)
{
    float res;

    res = (((float)my_time.tv_sec * (float)1000) + ((float)my_time.tv_usec / (float)1000));
    return (res);
}