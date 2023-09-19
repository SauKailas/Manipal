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
	int sockfd, newsockfd, clilen, c, n;
	int a, b;
	float res;
	char op;

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
			n = read(newsockfd, &a, sizeof(a));
			n = read(newsockfd, &b, sizeof(b));
			n = read(newsockfd, &op, sizeof(op));

			printf("Received: %d %c %d\n", a, op, b);

			switch(op)
			{
				case '+':
					res = a + b;
					break;
				case '-':
					res = a - b;
					break;
				case '*':
					res = a * b;
					break;
				case '/':
					res = a / b;
					break;
			}

			n = write(newsockfd, &res, sizeof(res));
			printf("Sent: %.2f\n", res);
		}
		else
			close(newsockfd);
	}

	return 0;
}