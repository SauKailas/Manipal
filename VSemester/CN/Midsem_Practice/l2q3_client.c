#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

#define PORTNO 10200

int main()
{
	struct sockaddr_in address;
	int sockfd, result, n, pid;
	char tt[256];

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address.sin_port = htons(PORTNO);

	result = connect(sockfd, (struct sockaddr*)&address, sizeof(address));
	if(result == -1)
	{
		printf("Client Error!\n");
		exit(1);
	}

	n = read(sockfd, &pid, sizeof(pid));
	printf("Process ID: %d\n", pid);

	n = read(sockfd, tt, sizeof(tt));
	printf("Time: %s\n", tt);

	return 0;
}