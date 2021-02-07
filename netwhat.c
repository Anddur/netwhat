#include <stdio.h>
#include <string.h>

#include "ft_split.c"
#include "IP_calculator.c"

int main()
{
	char    ipadd[19];
	int    mask;
	char	**split_ip;
	int 	i = 0;
	char	*uno;
	char	*due;
	char	*tre;
	char	*quattro;
	char	classe;
	int		CDIR;
	char	*netmask;
	int		priv = 0;
	char	*netadd;
	char	*broadd;
	char	**split_net;

	puts("");
	puts("\e[1;95m""***...***..*********..*********.......................................................");
	puts("****..***..*********..*********.......................................................");
	puts("*****.***..*********.....***..........................................................");
	puts("***.*****..*********.....***..........................................................");
	puts("***..****..*********.....***..........................................................");
	puts("***...***..*********.....***........................................................AD""\x1b[0m");
	//puts("--------------------------------------------------------------------------------------");
	puts("");
	printf("1)VLSM 2)CDIR:              	");
	scanf("%d", &mask);
	puts("");
	netmask = malloc(sizeof(char) * 20);
	netadd = malloc(sizeof(char) * 20);
	broadd = malloc(sizeof(char) * 20);
	if (mask == 1)
	{
		printf("inserisci netmask:			");
		scanf("%s", netmask);
		CDIR = conv_net(netmask);
	}
	else if (mask == 2)
	{
		printf("inserisci CDIR:			");
		scanf("%d", &CDIR);
		netmask = conv_cdir(CDIR);
	}
	else
	{
		printf("ERROR");
		return (0);
	}
	printf("Inserisci IP:               	");
	scanf("%s", ipadd);
	puts("");
	printf("CIDR:				""\e[1;94m""%d\n""\x1b[0m", CDIR);
	printf("NETMASK:			""\e[1;94m""%s\n""\x1b[0m", netmask);
	split_ip = ft_split(ipadd, '.');
	uno = split_ip[0];
	due = split_ip[1];
	tre = split_ip[2];
	quattro = split_ip[3];
	classe = class_cal(uno);
	printf("CLASSE:				""\e[1;93m""%c\n""\x1b[0m", classe);
	priv = priv_cal(uno, due, tre, quattro);
	if (priv)
		printf("\e[1;93m""					PRIVATO\n""\x1b[0m");
	else
		printf("\e[1;93m""				PUBBLICO\n""\x1b[0m");
	split_net = ft_split(netmask, '.');
	puts("--------------------------------------------------------------------------------------");
	netadd_cal(split_ip, split_net);
	puts("--------------------------------------------------------------------------------------");
	bradd_cal(split_ip, split_net);
	puts("--------------------------------------------------------------------------------------");
	num_host(CDIR);
	puts("--------------------------------------------------------------------------------------");

}
