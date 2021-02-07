# netwhat

This repo contains a simple program that does all the necessary calculations needed to easily pass the 42's netwhat project.

Download the repo to any folder on your system with the following command:

<code>git clone https://github.com/Anddur/netwhat.git</code>

Compile with the following command:

<code>gcc netwhat.c</code>

Run with the following command:

<code>./a.out</code>

Once done, it will ask you which subnet mask format you want to use:

<samp>1)VLSM 2)CDIR               </samp>

Digit 1 for VLSM, 2 for CDIR.

Next, you will enter the IP address, making sure it is written in the correct format.

<samp>Insert IP:                  </samp>

Once entered, the program will give the following information:

- CIDR e VLSM corrispondenti
- Class
- Public or private
- Network address
- Broadcast address
- Host available

The output will look like the following:

<pre>
<code>
***...***..*********..*********.......................................................
****..***..*********..*********.......................................................
*****.***..*********.....***..........................................................
***.*****..*********.....***..........................................................
***..****..*********.....***..........................................................
***...***..*********.....***........................................................AD

1)VLSM 2)CDIR:              	2

inserisci CDIR:			27
Inserisci IP:               	1.1.1.1

CIDR:				27
NETMASK:			255.255.255.224
CLASSE:				A
				PUBBLICO
--------------------------------------------------------------------------------------
NETWORK ADDRESS:							1.1.1.0
--------------------------------------------------------------------------------------
BROADCAST ADDRESS:							1.1.1.31
--------------------------------------------------------------------------------------
N DI HOST:								30
--------------------------------------------------------------------------------------
</code>
</pre>
