#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<time.h>

#define PORTNO 10200

int main()
{
	struct sockaddr_in seraddr, cliaddr;
	int sockfd, newsockfd, clilen, n, pid;
	char tt[256];

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	seraddr.sin_family = AF_INET;
	seraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	seraddr.sin_port = htons(PORTNO);

	bind(sockfd, (struct sockaddr*)&seraddr, sizeof(seraddr));

	listen(sockfd, 5);

	while(1)
	{
		newsockfd = accept(sockfd, (struct sockaddr*)&cliaddr, &clilen);

		if(fork() == 0)
		{
			pid = getpid();
			printf("Created new child with ID: %d\n", pid);
			n = write(newsockfd, &pid, sizeof(pid));

			time_t t;
			time(&t);
			strcpy(tt, ctime(&t));
			printf("Time: %s\n", tt);
			n = write(newsockfd, tt, sizeof(tt));
		}	
		else
			close(newsockfd);
	}

	return 0;
}