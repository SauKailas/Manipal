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
	struct sockaddr_in address;
	int sockfd, res;
	struct student st1, st2;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address.sin_port = htons(PORTNO);

	res = connect(sockfd, (struct sockaddr*)&address, sizeof(address));
	if(res == -1)
	{
		printf("Client Error!\n");
		exit(0);
	}

	printf("Enter student name: ");
	gets(st1.name);
	printf("Enter registration number: ");
	scanf("%d", &st1.regno);

	res = write(sockfd, &st1, sizeof(st1));
	res = read(sockfd, &st2, sizeof(st2));

	printf("\nReceived Details:\n");
	printf("Name: %s\n", st2.name);
	printf("Reg. No.: %d\n", st2.regno);

	close(sockfd);

	return 0;
}