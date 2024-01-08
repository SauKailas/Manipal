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
	int sockfd, len, n = 1, result;
	char buf[256];

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address.sin_port = htons(PORTNO);

	result = connect(sockfd, (struct sockaddr_in*)&address, sizeof(address));
	if(result == -1)
	{
		printf("\nCLIENT ERROR!\n\n");
		exit(1);
	}

	printf("Enter a string:\n");
	gets(buf);

	n =	write(sockfd, buf, sizeof(buf));
	printf("Sent: %s\n", buf);

	n = read(sockfd, buf, sizeof(buf));
	printf("Received: %s\n", buf);

	return 0;
}	