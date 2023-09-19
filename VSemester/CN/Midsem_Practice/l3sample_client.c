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
	int sockfd, n;
	char buf[256];

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address.sin_port = htons(PORTNO);

	printf("Enter a string: ");
	gets(buf);

	n = sendto(sockfd, buf, sizeof(buf), 0, (struct sockaddr*)&address, sizeof(address));
	printf("Sent: %s\n", buf);

	n = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr*)&address, sizeof(address));
	printf("Received: %s\n", buf);

	return 0;
}