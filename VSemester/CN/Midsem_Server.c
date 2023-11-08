#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

#define PORTNO 10200

struct student
{
	char name[100];
	int regno;
};

int main()
{
	struct sockaddr_in seraddr, cliaddr;
	int sockfd, newsockfd, res, clilen;
	struct student st1;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	seraddr.sin_family = AF_INET;
	seraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	seraddr.sin_port = htons(PORTNO);

	bind(sockfd, (struct sockaddr*)&seraddr, sizeof(seraddr));

	listen(sockfd, 5);

	while(1)
	{
		newsockfd = accept(sockfd, (struct sockaddr*)&cliaddr, &clilen);

		res = read(newsockfd, &st1, sizeof(st1));
		printf("Received Details:\n");
		printf("Name: %s\n", st1.name);
		printf("Reg. No.: %d\n", st1.regno);

		struct student st2;
		strcpy(st2.name, "Lionel Messi");
		st2.regno = 1010101010;
		res = write(newsockfd, &st2, sizeof(st2));
		printf("Sent structure back to client!\n");
	}

	return 0;
}