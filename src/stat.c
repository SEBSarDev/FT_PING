#include "../inc/ft_ping.h"

extern struct info_time resume;

void find_min_and_max()
{
	struct rtt_list *stock;
	
	if (!resume.all_rtt)
		return;
	stock = resume.all_rtt;
	while(resume.all_rtt)
	{
		if (resume.min.tv_sec == -1 || timercmp(&resume.all_rtt->rtt, &resume.min, <))
			resume.min = resume.all_rtt->rtt;
		if (resume.max.tv_sec == -1 || timercmp(&resume.all_rtt->rtt, &resume.max, >))
			resume.max = resume.all_rtt->rtt;
		resume.all_rtt = resume.all_rtt->next;
	}
	resume.all_rtt = stock;
}

void find_moy()
{
	struct rtt_list *stock;
	float all;
	
	all = 0;
	if (!resume.all_rtt)
		return;
	stock = resume.all_rtt;
	while(resume.all_rtt)
	{
		all += resume.all_rtt->millis;
		resume.all_rtt = resume.all_rtt->next;
	}
	resume.all_rtt = stock;
	resume.moy = all/resume.received;
}

void find_mdev()
{
	struct rtt_list *stock;
	float all;
	float diff;
	
	all = 0;
	if (!resume.all_rtt)
		return;
	stock = resume.all_rtt;
	while(resume.all_rtt)
	{
		diff = resume.moy - resume.all_rtt->millis;
		if (diff < 0)
			diff *= -1;
		all += diff;
		resume.all_rtt = resume.all_rtt->next;
	}
	resume.all_rtt = stock;
	resume.mdev = all/resume.received;
}

void print_final_stat(struct dest_info dest, struct timeval *final)
{
    float min;
    float max;
    float time;
    int percent;
    struct timeval diff;

  	timersub(final, &resume.start, &diff);
	find_min_and_max();
    find_moy();
	find_mdev();
    percent = (((resume.nb - resume.received) * 100) / resume.nb);
    min = calcul_millisecond(resume.min);
    max = calcul_millisecond(resume.max);
    time = calcul_millisecond(diff);
    printf("\n--- %s ping statistics ---\n", dest.hostname);
	printf("%d packets transmitted, %d received, ", resume.nb, resume.received);
    if (resume.errors)
        printf("+%d errors, ", resume.errors);
    printf("%d%% packet loss, time %.0fms\n", percent, time);
    if (resume.received)
        printf("rtt min/avg/max/mdev = %.3f/%.3f/%.3f/%.3f ms", min, resume.mdev, max, resume.moy);
    printf("\n");
}

void print_inter_stat()
{
    float min;
    float max;
    int percent;

	find_min_and_max();
    find_moy();
	find_mdev();
    percent = (((resume.nb - resume.received) * 100) / resume.nb);
    min = calcul_millisecond(resume.min);
    max = calcul_millisecond(resume.max);
    printf("\n%d/%d packets, %d%% loss", resume.received, resume.nb, percent);
    if (resume.received)
        printf(", min/avg/ewma/max = %.3f/%.3f/%.3f/%.3f ms", min, resume.moy, resume.mdev, max);
    printf("\n");
    resume.print = 0;
}