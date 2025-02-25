#ifndef FT_PING_H

# define FT_PING_H
# define USAGE 1
# define ERR_DNS 2
# define FCTN_FAIL 3
# define BROADCAST 4

# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>
# include <netinet/ip_icmp.h>
# include <arpa/inet.h>
# include <stdio.h>
# include <string.h>
# include <signal.h>
# include <netinet/in.h>
# include <errno.h>
# include <sys/time.h>
# include "../libft/libft.h"

struct dest_info {
    char *hostname;
    char *ipv4;
    struct addrinfo *addr;
};

struct rtt_list {
    struct rtt_list *prev;
    struct timeval rtt;
    float millis;
    struct rtt_list *next;
};

struct info_time {
    int loop;
    int v;
    int print;
    int ready;
    int errors;
    int nb;  // packet envoyé
    int received;  //packet reçu
    struct timeval start;  //lancement de ping
    struct timeval min;  //meilleur temps
    float moy;  //temps moyen
    struct timeval max;  //pire temps
    float mdev; //moyenne des ecarts entre chaque ping (standard deviation, = ecart type = ecart du rtt de chaque packet avec la moyenne de rtt)
    struct rtt_list *all_rtt; //stock des rtt de chaque packet envoyé pour calculer mdev
};


void free_all(struct dest_info *dest, int sockfd);
unsigned short checksum(void *addr, size_t count);
int init_resume(struct dest_info *dest);
int fill_icmp(struct icmphdr *icmp, int *i, char *buffer);
int get_headers(char *rec, struct icmphdr **icmp, struct timeval **time , struct icmphdr **icmp_o);
struct timeval *store_rtt(struct timeval *send_at, struct timeval *received_at);
int receive(int sockfd, struct dest_info *dest);
void find_min_and_max();
void find_moy();
void find_mdev();
int error_msg(int err, char *str);
void print_type_error(int type, int code);
void print_code_error_12(int code);
void print_code_error_11(int code);
void print_code_error_5(int code);
void print_code_error_3(int code);
int get_args(int argc, char **argv);
int send_icmp(struct sockaddr_in *dest_addr, int sockfd, int *i);
void print_sock_info(struct dest_info *dest, int sockfd);
void print_final_stat(struct dest_info dest, struct timeval *final);
void print_start(struct dest_info *dest);
float calcul_millisecond(struct timeval my_time);
void print_inter_stat();
void print_infos_source_reply(int recv, struct iphdr *ip, struct dest_info *dest);
void print_bad_response(struct iphdr *ip, struct icmphdr *stock_icmp, struct icmphdr *stock_icmp_ret);
void print_infos_header_reply(struct icmphdr *stock_icmp, struct iphdr *ip, struct timeval *time_to);

#endif