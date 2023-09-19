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
	int arr[5];

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

	printf("Enter 5 elements: ");
	for(int i=0; i<5; i++)
		scanf("%d", &arr[i]);

	n = write(sockfd, arr, sizeof(arr));
	printf("Sent: ");
	for(int i=0; i<5; i++)
		printf("%d ", arr[i]);
	printf("\n");

	n = read(sockfd, arr, sizeof(arr));
	printf("Received: ");
	for(int i=0; i<5; i++)
		printf("%d ", arr[i]);
	printf("\n");

	n = read(sockfd, &pid, sizeof(pid));
	printf("PID: %d\n", pid);

	return 0;
}