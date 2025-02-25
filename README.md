# FT_PING
Recode ping in C.

To test this program, please use it in debian machine and run :
```
make
./ft_ping <IPv4 addr>
```

man:
- https://www.man-linux-magique.net/man8/ping.html

raw_socket:
- https://manpages.ubuntu.com/manpages/noble/man7/raw.7.html
- ! la couche ipv4 genere un en tete IP lors de l'envoi d'un paquet sauf si l'option IP_HDRINCL est active sur le socket, on peut modifier les options de l'en tete grace a setsockopt.

setsockopt options:
- https://refspecs.linuxbase.org/LSB_3.1.1/LSB-Core-generic/LSB-Core-generic/baselib-setsockopt-2.html

entete ip: 
- https://racine.gatoux.com/lmdr/index.php/le-datagramme-ip/#:~:text=L'ent%C3%AAte%20IP%20standard%20n,le%20pr%C3%A9sentons%20succinctement%2C%20plus%20loin.
- https://www.frameip.com/entete-ip/

entet icmp:
- https://book.huihoo.com/iptables-tutorial/x1078.htm
- https://www.frameip.com/entete-icmp/

calcul checksum :
- https://www.packetmania.net/en/2021/12/26/IPv4-IPv6-checksum/
- https://www.google.com/amp/s/www.developpez.net/forums/d1252011/c-cpp/c/reseau/checksum-icmp-ip/
- meme chose pour ip et icmp mais sur checun leur propre structure. Pour calculer le checksum il faut additioner chaque mots de 16 bits de la structure, et garder le complement du resultat.
- ne pas oublie de mettre la valeur checksum de la structure a 0 avant de lancer le calcul.

Some usefull links:
- https://www.kentik.com/kentipedia/ping-command-in-network-troubleshooting-and-monitoring/#:~:text=When%20you%20issue%20a%20ping,that%20ask%20for%20a%20response.
- https://www.geeksforgeeks.org/internet-control-message-protocol-icmp/
- https://www.opensourceforu.com/2015/03/a-guide-to-using-raw-sockets/
- https://www.geeksforgeeks.org/error-detection-in-computer-networks/
- https://www.geeksforgeeks.org/domain-name-system-dns-in-application-layer/
- https://www.geeksforgeeks.org/ping-in-c/
- https://gcore.com/learning/how-to-change-ttl-in-linux/
- https://networkengineering.stackexchange.com/questions/12858/interpreting-ttl-in-ping-results
- http://n8on.free.fr/hackzines/counterstrike/3/rawsockets.html
- https://stackoverflow.com/questions/9688899/sending-icmp-packets-in-a-c-program
- https://www.gta.ufrj.br/ensino/eel878/sockets/connectman.html
- https://www.gta.ufrj.br/ensino/eel878/sockets/sockaddr_inman.html
- https://www.frameip.com/entete-icmp/?video=62#video-62

sudo:
- https://stackoverflow.com/questions/3214297/how-can-my-c-c-application-determine-if-the-root-user-is-executing-the-command

ttl:
- https://stackoverflow.com/questions/8585888/how-to-update-the-ttl-in-c-programming
- https://refspecs.linuxbase.org/LSB_5.0.0/LSB-Core-generic/LSB-Core-generic/baselib-setsockopt-2.html


ip_icmp.h:
- https://sites.uclouvain.be/SystInfo/usr/include/netinet/ip_icmp.h.html

man pages:
- https://man7.org/linux/man-pages/man3/getaddrinfo.3.html
- http://manpagesfr.free.fr/man/man3/inet_ntop.3.html
- https://pubs.opengroup.org/onlinepubs/007904975/functions/setsockopt.html


iphdr vs ip:
- https://stackoverflow.com/questions/42840636/difference-between-struct-ip-and-struct-iphdr#:~:text=struct%20ip%20and%20struct%20iphdr%20are%20two%20different%20definitions%20of,defined%20in%20%3Clinux%2Fip.


rtt (round trip time):
- il semble que ce soit a l'hote de se rappeler de la date d'envoi de chaque echo request, pour ne pas saturer la memoire, il envoie la donnée dans les data de la request: (cf man de ping "Les datagrammes ECHO_REQUEST comprennent un en-tête IP  et un  en-tête  ICMP,  suivis  d'une  « struct timeval »") ainsi, dans le retour de l'echo reply, la data sera retransmise egalement (https://superuser.com/questions/1086312/why-does-icmp-echo-request-and-echo-reply-packets-contain-a-data-portion)
- https://networkengineering.stackexchange.com/questions/53253/where-is-pings-round-trip-time-stored-in-the-ip-header
- il semble que la plupart utilise gettimeofday mais clock_gettime est la version plus recente
- https://stackoverflow.com/questions/70175164/icmp-timestamps-added-to-ping-echo-requests-in-linux-how-are-they-represented-t

substract struct timeval
- https://stackoverflow.com/questions/67912613/how-to-calculate-difference-between-2-timevals

le ttl des routers est plus long que celui des machines linux de base (il est de 64 pour les machines linux ordinaire)


change ttl value :
```
sysctl net.ipv4.ip_default_ttl
sudo sysctl -w net.ipv4.ip_default_ttl=2
```

-v doit montrer le code et le type du retour (egalement en cas d'erreur)

pas obligé d'avoir le dns dans le retour de paquet : ex
PING google.com (172.217.20.174) 56(84) bytes of data.
64 octets de waw02s07-in-f174.1e100.net (172.217.20.174) : icmp_seq=1 ttl=116 temps=6.90 ms
-> pas besoin de waw02s07-in-f174.1e100.net

ex d'addresse ip non fonctionnelle : 142.142.142.142

usage de getaddrinfo pour trouver l'addresse ip a parir d'un dns:
hint specifie un critere de selection dns les addresse qui sont renvoyer dans addr
ces critere de selection peuvent etre ai_family (ici AF_INET) donc ca va filtrer que les addresses renvoyer qui sont ipv4
on peut aussi filtrer grace a ai_socktype (ici uniquement raw_socket) et ai_protocole (pour nous icmp)
demande les info de l'addresse en fonction du nom donné, et filtre les reponse (uniquement ipv4, acceptant raw_socket, et icmp protocole)
Ensuite on recupere l'adresse de la premiere structure, elle est alors sous forme d'une structure contenant un unsigned long qu'il va falloir traduire en str
puis on iutilise inet_netop traduit l'ipv4 qui est en unsigned long dans *ptr et le place dans en char * dans str (16 octet max-> taille d'une ipv4 + \0)


struct addrinfo {
    int              ai_flags;
    int              ai_family;
    int              ai_socktype;
    int              ai_protocol;
    size_t           ai_addrlen;
    struct sockaddr *ai_addr;
    char            *ai_canonname;
    struct addrinfo *ai_next;
};

struct sockaddr {
    sa_family_t     sa_family;      /* Address family */
    char            sa_data[];      /* Socket address */
};
== 
struct sockaddr_in {
    sa_family_t     sin_family;     /* AF_INET */
    in_port_t       sin_port;       /* Port number */
    struct in_addr  sin_addr;       /* IPv4 address */
};

struct in_addr {
    unsigned long s_addr;  // load with inet_aton()
};

struct icmphdr
{
  u_int8_t type;                /* message type */
  u_int8_t code;                /* type sub-code */
  u_int16_t checksum;
  union
  {
    struct
    {
      u_int16_t        id;
      u_int16_t        sequence;
    } echo;                        /* echo datagram */
    u_int32_t        gateway;        /* gateway address */
    struct
    {
      u_int16_t        __unused;
      u_int16_t        mtu;
    } frag;                        /* path mtu discovery */
  } un;
};

RESUME:
On utilise un RAW_SOCKET(socket brut, qui necessite privilege root) et on utilise le protocole ICMP.
Le socket brut permet de determiner nous meme chaque section du packet, y compris les header tandis que les socket non brut permettent de determiner uniquement la payload, les datas envoyé. Ainsi ici avec le raw socket on peut configurer les header et donner l'addresse de destination, l'addresse source, le protocole, incorporer un header icmp pour dire que c'est un echo request qu'on envoie...
Le protocol ICMP permet d'avoir un retour sur un paquet envoyé, il nous permet de savoir si un paquet est recu ou non contrairement au protocol IP, ou l'on ne peut pas savoir s'il est arrivé a destination. Donc quand on envoit un paquet avec ICMP, si ce dernier n'arrive pas a destination pour une quelquonque raison, le dernier router qui se trouve en pocession du paquet va renvoyer vers l'addresse source un autre paquet ICMP qui va contenir en data le header du paquet qui a echoué (https://www.cloudflare.com/fr-fr/learning/ddos/glossary/internet-control-message-protocol-icmp/). Ainsi quand on envoit un echo request avec ICMP, soit on va recevoir un paquet "echo reply" de la  part de l'addresse destinataire, ce qui nous indique a nous, hôte, que notre paquet a bien été recu, soit on va recevoir un paquet ICMP de qq d'autre, qui va nous indiquer dans son header le type de code erreur, et qui va nous renvoyer en data une copie du paquet qui a échoué.
le protocol icmp fait partie de la couche 3, la couche reseau. son header est encapsuler dans celui du protocol ip.
Le paquet encoyé aura pour taille par defaut 84 octets, il comprend:
  - 20 octets pour l'en tete IP
  - 8 octets pour l'en tete icmp
  - 56 octets de data arbitraire (valeur par default mais peut etre changer grace a l'option -s)

  L'en tete IP peut etre stocker soit dans une structure iphdr(pour linux uniquement, provenant de <linux/ip.h>) :
  struct iphdr {
    #if defined(__LITTLE_ENDIAN_BITFIELD)
	__u8	ihl:4,
		version:4;
#elif defined (__BIG_ENDIAN_BITFIELD)
	__u8	version:4,    -> version = 4 (ipv4)
  		ihl:4;
#endif               -> ihllongueur de l'entete en mot de 32 bits, donc pour nous 5 (20 octets)

	__u8	tos;         -> type of service (niveau de priorité dans la transmission du paquet) par defaut il a 0 dans un ping
	__u16	tot_len;     -> total length en tete compris, pour nous ca sera 84
	__u16	id;          -> identificateur (getpid), utile pour la fragmentation donc pas vraiment utile pour nous.
	__u16	frag_off;    -> fragment offset: permet de savoir si le paquet est fragmenter ou non (1024 octets max par frragment, on est a 84 pour ping donc fragmentation pas necessaire pour nous)
	__u8	ttl;         -> time to live = le nombre de rooter que le  packet a le droit de rencontrer avant d'être considéré comme "a jeter", depuis une machine linux c'est generalement 64.
	__u8	protocol;     -> protocol pour nous icmp (num 1)
	__u16	check;       -> checksum -> fait la somme des valeurs des octets de l'entete (compte les 1) et stock le resultat
	__u32	saddr;       -> addresse source en unsigned long
	__u32	daddr;       -> addresse destination en unsigned long
};

soit dans une structure ip (tout system unix, a privilegier donc), provenant de la librairie <netinet/ip.h>, les elements sont les meme:
struct ip
  {
#if __BYTE_ORDER == __LITTLE_ENDIAN
    unsigned int ip_hl:4;     /* header length */
    unsigned int ip_v:4;       /* version */
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
    unsigned int ip_v:4;     /* version */
    unsigned int ip_hl:4;    /* header length */
#endif
    u_int8_t ip_tos;  /* type of service */
    u_short ip_len;       /* total length */
    u_short ip_id;       /* identification */
    u_short ip_off;      /* fragment offset field */
#define        IP_RF 0x8000     /* reserved fragment flag */
#define        IP_DF 0x4000    /* dont fragment flag */
#define        IP_MF 0x2000     /* more fragments flag */
#define        IP_OFFMASK 0x1fff       /* mask for fragmenting bits */
    u_int8_t ip_ttl;          /* time to live */
    u_int8_t ip_p;           /* protocol */
    u_short ip_sum;        /* checksum */
    struct in_addr ip_src, ip_dst;     /* source and dest address */
  };



puis l'entete icmp va comprendre 
- type        -> 8 pour echo_request
- code        -> pour nous : 0 (c'est le seul code dispoible pour un type 8)
- checksum    -> checksum de l'entete icmp + des datas.
- identifier  -> correspond au pid
- sequence    -> commence a 1 et incremente a chaque paquet envoyé, comme ça peut savoir si certains on été perdus.


L'option IPPROTO_ICMP de socket permet de n'avoir a s'occuper que de l'en tete icmp, l'en tete ip sera automatiquement rempli par le noyau.
En revanche si on utilise l'option IPPROTO_RAW en ouvrant le socket, la partie IP devra integralement etre rempli par nous, y compris le checksum de l'en tete ip et les addresse source et destination. 
pour avoir l'addresse source : on cree un socket udp par exemple, on cree une connexion factice avec un serveur quelquonque, on utilise getsokname pour recuperer l'address ip de l'interface reseau locale utilisé lors de la connexion.

```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>

// Fonction pour obtenir l'IP locale
void get_local_ip(char *buffer) {
    int sock;
    struct sockaddr_in name;
    socklen_t namelen = sizeof(name);

    // Création d'un socket UDP temporaire
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    // Connexion à une adresse IP distante factice (Google DNS 8.8.8.8)
    struct sockaddr_in remote_addr;
    memset(&remote_addr, 0, sizeof(remote_addr));
    remote_addr.sin_family = AF_INET;
    remote_addr.sin_addr.s_addr = inet_addr("8.8.8.8");
    remote_addr.sin_port = htons(53);  // Port DNS (53)

    connect(sock, (const struct sockaddr *)&remote_addr, sizeof(remote_addr));

    // Récupérer l'IP locale après connexion
    getsockname(sock, (struct sockaddr *)&name, &namelen);
    inet_ntop(AF_INET, &name.sin_addr, buffer, 100);

    close(sock);
}

int main() {
    char local_ip[100];
    get_local_ip(local_ip);
    printf("Adresse IP locale: %s\n", local_ip);

    return 0;
}

```

Dans notre cas, on allegera le code en utilisant directement IPPROTO_ICMP et en laissant le noyau s'occuper de l'entete ip seul.

Au moment d'envoyer le paquet, celui ci correspond a un pointeur vers une addresse qui correspond au debut de notre packet. c'est a dire, soit à l'en tete ip si on utilise IPPPROTO_RAW a l'ouverture du socket soit a l'en tete icmp si on utilise IPPROTO_ICMP.

donc notre packet ressemble à :
________________________________
| ICMP header | data........... |
|_____________|_________________|

A l'interieur de la boucle, il est neccessaire de mettre un sleep, sinon on sature tout, et sendto fail avec cet erreur "No buffer space available" (https://stackoverflow.com/questions/65261295/udp-datagram-sockets-what-are-the-possible-causes-of-failure-of-send-for-no)


Pour la RECEPTION de la reponse:
- il faut que l'on trie les paquets qui correspondent a un potentiel reponse, donc soit c'est un echo reply et dans ce cas les id et frequence du header icmp correspondent à ceux qu'on a envoyé. Soit il y a eu une erreur et le paquet recu comprends en data une copie du paquet qu'on a envoyé, on peut donc retrouver dans les datas le paquets auquel correspond cette erreur.
- une fois que l'on a ces informations, on peut les extraires, imprimée les infos, et stocker celle qui nous seront utiles pour faire la moyenne etc...


probleme de timing.
Si on effectue le programme dans une boucle sans sleep, le ping va saturer et planter. Le problemen c'est qu'avec sleep, le temps est rallongé inutilement est se retrouve tres different du vrai ping. En effet, si on fait un sleep dans la boucle, il va attendre le sleep avant de retourner au debut de la boucle pour eventuellement recevoir un packet, le temps de la reception du paquet est donc retardé du temps du sleep.
On a plusieurs solutions pour parer cela, et permettre d'executer l'envoi de paquet regulierement mais pas sans arret, mais sans en revanche retarder la lecture d'arrivée de paquet:
- pthread(), on execute le sendto() en arriere plan en mettant un sleep dans la boucle du sendto
- alarm() qui permet d'envoyer un signal regulier, en capturant le signal avec signal() on peut l'associer a une fonction a executer. Une fois qu'on appelle alarme, en lui donnant en parametre des seconde, il va executer la fonction correspondante dans n seconde.
- setitimer() qui est comme alarm mais beaucoup plus precis (on peut appeler le signal toutes les n micriseconde, contrairement à alarm qui compte en seconde). Contrairement a alarm, on l'appelle une fois et il va s'executer toutes les n secondes.

pthread est plus flexible mais pas forcement utile pour une tache aussi simple que celle que nous cherchons. alarm et setitimer sont donc a privilegier. Avec setimer, une fois qu'on le lance une premiere fois, il va executer la fonction toute le n seconde sans se soucier de ce qui a pu etre fait ailleurs dans le programme. Donc s'il y a un peu de retard quelque part, on peut peut etre avoir des conflits. Il vaut mieux donc utiliser alarm, que l'on mettra donc dans la boucle, ce qui permettra de commencer a compter seulement a la fin d'un send et de faciliter l'implementation de la fonction. (avec setitimer, il aurait fallu mettre le sendto() dans la fonction liée au sigalrm, mais les arguments auraient du etre passé en global) Par defaut un ping envoi un packet toutes les secondes. 
