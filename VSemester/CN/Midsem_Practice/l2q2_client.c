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
	int sockfd, result, n;
	int a, b;
	float res;
	char op;

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

	printf("Enter the operator: ");
	scanf("%c", &op);

	printf("Enter two numbers: ");
	scanf("%d %d", &a, &b);

	n = write(sockfd, &a, sizeof(a));
	n = write(sockfd, &b, sizeof(b));
	n = write(sockfd, &op, sizeof(op));
	printf("Sent: %d %c %d\n", a, op, b);

	n = read(sockfd, &res, sizeof(res));
	printf("Received: %.2f\n", res);

	return 0;
}