#include <stdio.h>
#include <unistd.h>
#include <math.h>

static	size_t		ft_nsize(int n)
{
	size_t size;

	size = (n < 0 ? 1 : 0);
	while (1)
	{
		n /= 10;
		size++;
		if (n == 0)
			break ;
	}
	return (size);
}

char				*ft_itoa(int n)
{
	size_t	size;
	char	*itoa;
	long	number;

	number = n;
	size = ft_nsize(n);
	if (!(itoa = calloc(size + 1, sizeof(char))))
		return (NULL);
	if (number < 0)
	{
		itoa[0] = '-';
		number *= -1;
	}
	itoa[size] = '\0';
	while (1)
	{
		itoa[size - 1] = (number % 10) + 48;
		number /= 10;
		size--;
		if (number == 0)
			break ;
	}
	return (itoa);
}

char    class_cal(char *str)
{
	char res;
	int uno = atoi(str);
	if (uno >= 1 && uno <= 127)
		res = 'A';
	else if (uno >= 128 && uno <= 191)
		res = 'B';
	else if (uno >= 192 && uno <= 223)
		res = 'C';
	else if (uno >= 224 && uno <= 239)
		res = 'D';
	else if (uno >= 240 && uno <= 255)
		res = 'E';
	return (res);
}

int     priv_cal(char *uno, char *due, char *tre, char *quattro)
{
	int unoi = atoi(uno);
	int duei = atoi(due);
	int trei = atoi(tre);
	int quattroi = atoi(quattro);
	if (unoi == 10)
		return (1);
	else if (unoi == 172 && duei >= 16 && duei <= 31)
		return (1);
	else if (unoi == 192 && duei == 168)
		return (1);
	else
		return (0);
}

char    *conv_cdir(int cdir)
{
	char *res;

	if (cdir == 8)
		res = "255.0.0.0";
	if (cdir == 9)
		res = "255.128.0.0";
	if (cdir == 10)
		res = "255.192.0.0";
	if (cdir == 11)
		res = "255.224.0.0";
	if (cdir == 12)
		res = "255.240.0.0";
	if (cdir == 13)
		res = "255.248.0.0";
	if (cdir == 14)
		res = "255.252.0.0";
	if (cdir == 15)
		res = "255.254.0.0";
	if (cdir == 16)
		res = "255.255.0.0";
	if (cdir == 17)
		res = "255.255.128.0";
	if (cdir == 18)
		res = "255.255.192.0";
	if (cdir == 19)
		res = "255.255.224.0";
	if (cdir == 20)
		res = "255.255.240.0";
	if (cdir == 21)
		res = "255.255.248.0";
	if (cdir == 22)
		res = "255.255.252.0";
	if (cdir == 23)
		res = "255.255.254.0";
	if (cdir == 24)
		res = "255.255.255.0";
	if (cdir == 25)
		res = "255.255.255.128";
	if (cdir == 26)
		res = "255.255.255.192";
	if (cdir == 27)
		res = "255.255.255.224";
	if (cdir == 28)
		res = "255.255.255.240";
	if (cdir == 29)
		res = "255.255.255.248";
	if (cdir == 30)
		res = "255.255.255.252";
	if (cdir == 31)
		res = "255.255.255.254";
	if (cdir == 32)
		res = "255.255.255.255";
	return (res);
}

int		conv_net(char *netmask)
{
	int res;

	if (strcmp(netmask,"255.0.0.0") == 0)
		res = 8;
	if (strcmp(netmask, "255.128.0.0") == 0)
		res = 9;
	if (strcmp(netmask, "255.192.0.0") == 0)
		res = 10;
	if (strcmp(netmask, "255.224.0.0") == 0)
		res = 11;
	if (strcmp(netmask,"255.240.0.0") == 0)
		res = 12;
	if (strcmp(netmask, "255.248.0.0") == 0)
		res = 13;
	if (strcmp(netmask, "255.252.0.0") == 0)
		res = 14;
	if (strcmp(netmask, "255.254.0.0") == 0)
		res = 15;
	if (strcmp(netmask, "255.255.0.0") == 0)
		res = 16;
	if (strcmp(netmask, "255.255.128.0") == 0)
		res = 17;
	if (strcmp(netmask, "255.255.192.0") == 0)
		res = 18;
	if (strcmp(netmask, "255.255.224.0") == 0)
		res = 19;
	if (strcmp(netmask, "255.255.240.0") == 0)
		res = 20;
	if (strcmp(netmask, "255.255.248.0") == 0)
		res = 21;
	if (strcmp(netmask, "255.255.252.0") == 0)
		res = 22;
	if (strcmp(netmask, "255.255.254.0") == 0)
		res = 23;
	if (strcmp(netmask, "255.255.255.0") == 0)
		res = 24;
	if (strcmp(netmask, "255.255.255.128") == 0)
		res = 25;
	if (strcmp(netmask, "255.255.255.192") == 0)
		res = 26;
	if (strcmp(netmask, "255.255.255.224") == 0)
		res = 27;
	if (strcmp(netmask, "255.255.255.240") == 0)
		res = 28;
	if (strcmp(netmask, "255.255.255.248") == 0)
		res = 29;
	if (strcmp(netmask, "255.255.255.252") == 0)
		res = 30;
	if (strcmp(netmask, "255.255.255.254") == 0)
		res = 31;
	if (strcmp(netmask, "255.255.255.255") == 0)
		res = 32;
	else
		printf("ERROR");

	return res;
}

void    netadd_cal(char **ip, char **net)
{
	int i = 0;
	int	    unoi;
	int	    duei;
	int	    trei;
	int	    quattroi;
	int	    unon;
	int	    duen;
	int	    tren;
	int	    quattron;
	int     unor;
	int     duer;
	int     trer;
	int     quattror;
	char    *r1;
	char    *r2;
	char    *r3;
	char    *r4;
	char    *res;

	unoi = atoi(ip[0]);
	duei = atoi(ip[1]);
	trei = atoi(ip[2]);
	quattroi = atoi(ip[3]);

	unon = atoi(net[0]);
	duen = atoi(net[1]);
	tren = atoi(net[2]);
	quattron = atoi(net[3]);

	unor = (unoi & unon);
	duer = (duei & duen);
	trer = (trei & tren);
	quattror = (quattroi & quattron);

	printf("\e[1;92m""NETWORK ADDRESS:							%d.%d.%d.%d\n""\x1b[0m", unor, duer, trer, quattror);
}

void    bradd_cal(char **ip, char **net)
{
	int i = 0;
	unsigned char	unoi;
	unsigned char	duei;
	unsigned char	trei;
	unsigned char	quattroi;
	unsigned char	unon;
	unsigned char	duen;
	unsigned char	tren;
	unsigned char	quattron;
	unsigned char    unor;
	unsigned char    duer;
	unsigned char    trer;
	unsigned char    quattror;
	char    *r1;
	char    *r2;
	char    *r3;
	char    *r4;
	char    *res;

	unoi = atoi(ip[0]);
	duei = atoi(ip[1]);
	trei = atoi(ip[2]);
	quattroi = atoi(ip[3]);

	unon = atoi(net[0]);
	duen = atoi(net[1]);
	tren = atoi(net[2]);
	quattron = atoi(net[3]);

	unor = (unoi | ~unon);
	duer = (duei | ~duen);
	trer = (trei | ~tren);
	quattror = (quattroi | ~quattron);

	printf("\e[1;92m""BROADCAST ADDRESS:							%d.%d.%d.%d\n""\x1b[0m", unor, duer, trer, quattror);
}

void	num_host(int cdir)
{
	int res;

	res = pow(2, (32 - cdir)) - 2;
	printf("\e[1;92m""N DI HOST:								%d\n""\x1b[0m", res);
}
