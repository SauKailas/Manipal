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
	int sockfd, newsockfd, clilen, n;
	char buf[256];

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	seraddr.sin_family = AF_INET;
	seraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	seraddr.sin_port = htons(PORTNO);

	bind(sockfd, (struct sockaddr*)&seraddr, sizeof(seraddr));

	listen(sockfd, 5);

	while(1)
	{
		newsockfd = accept(sockfd, (struct sockaddr*)&cliaddr, &clilen);

		n = read(newsockfd, buf, sizeof(buf));
		printf("Encrypted: %s\n", buf);

		for(int i=0; buf[i] != '\0'; i++)
			buf[i] -= 4;

		printf("Decrypted: %s\n", buf);
		n = write(newsockfd, buf, sizeof(buf));
	}

	return 0;
}