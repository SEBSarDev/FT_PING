#include "../inc/ft_ping.h"

extern struct info_time resume;

void print_code_error_3(int code)
{
		switch (code) {
		case 0:
			printf("Destination network unreachable ");
			break;
		case 1:
			printf("Destination host unreachable ");
			break;
		case 2:
			printf("Destination protocol unreachable ");
			break;
		case 3:
			printf("Destination port unreachable ");
			break;
		case 4:
			printf("Fragmentation required ");
			break;
		case 5:
			printf("Source route failed ");
			break;
		case 6:
			printf("Destination network unknown ");
			break;
		case 7:
			printf("Source host isolated ");
			break;
		case 8:
			printf("Timestamp reply ");
			break;
		case 9:
			printf("Network administratively prohibited ");
			break;
		case 10:
			printf("Host administratively prohibited ");
			break;
		case 11:
			printf("Network unreachable for ToS ");
			break;
		case 12:
			printf("Host unreachable for ToS ");
			break;
		case 13:
			printf("Communication administratively prohibited ");
			break;
		case 14:
			printf("Host Precedence Violation ");
			break;
		case 15:
			printf("Precedence cutoff in effect ");
			break;
		default:
			printf("");
	}
}
void print_code_error_5(int code)
{
		switch (code) {
		case 0:
			printf("Redirect Datagram for the Network ");
			break;
		case 1:
			printf("Redirect Datagram for the Host ");
			break;
		case 2:
			printf("Redirect Datagram for the ToS & network ");
			break;
		case 3:
			printf("Redirect Datagram for the ToS & host ");
			break;
		default:
			printf("");
	}
}

void print_code_error_11(int code)
{
		switch (code) {
		case 0:
			printf("Time To Live exceeded ");
			break;
		case 1:
			printf("Fragment reassembly time exceeded ");
			break;
		default:
			printf("");
	}
}
void print_code_error_12(int code)
{
		switch (code) {
		case 0:
			printf("Pointer indicates the error ");
			break;
		case 1:
			printf("Missing a required option ");
			break;
		case 2:
			printf("Bad length ");
			break;
		default:
			printf("");
	}
}

void print_type_error(int type, int code)
{
	switch (type) {
		case 3:
			print_code_error_3(code);
			break;
		case 5:
			print_code_error_5(code);
			break;
		case 8:
			printf("Echo request ");
			break;
		case 9:
			printf("Router advertisement ");
			break;
		case 10:
			printf("Router solicitation ");
			break;
		case 11:
			print_code_error_11(code);
			break;
		case 12:
			print_code_error_12(code);
			break;
		case 13:
			printf("Timestamp ");
			break;
		case 14:
			printf("Timestamp reply ");
			break;
		default:
			printf("");
	}
}

int error_msg(int err, char *str)
{
	switch (err) {
		case USAGE:
			printf("Usage\n  ping [options] <destination>\n\nOptions:\n  \
<destination>  dns name or ipv4 address\n  -v  verbose output\n  \
-?  help\n");
			break;
		case ERR_DNS:
			printf("Unknown DNS name\n");
			break;
		case FCTN_FAIL:
			printf("Function %s failed.", str);
            break;
        case BROADCAST:
            printf("ft_ping: Permission denied. \
If you are trying to ping broadcast, this program is not enable to do it. Sorry.");
		default:
			printf("%s\n", str);
	}
	return (-1);
}