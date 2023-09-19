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
	struct sockaddr_in seraddr, cliaddr;
	int sockfd, clilen, n;
	char buf[256];

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);

	seraddr.sin_family = AF_INET;
	seraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	seraddr.sin_port = htons(PORTNO);

	bind(sockfd, (struct sockaddr*)&seraddr, sizeof(seraddr));

	n = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr*)&cliaddr, &clilen);
	printf("Received: %s\n", buf);

	n = sendto(sockfd, buf, sizeof(buf), 0, (struct socaddr*)&cliaddr, &clilen);
	printf("Sent: %s\n", buf);

	return 0;
}