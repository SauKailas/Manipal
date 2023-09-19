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
	int sockfd, n, len, rows, cols;

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address.sin_port = htons(PORTNO);

	printf("Enter the number of rows: ");
	scanf("%d", &rows);

	printf("Enter the number of columns: ");
	scanf("%d", &cols);

	len = sizeof(address);

	n = sendto(sockfd, &rows, sizeof(rows), 0, (struct sockaddr_in*)&address, len);
	n = sendto(sockfd, &cols, sizeof(cols), 0, (struct sockaddr_in*)&address, len);

	for(int i=0; i<rows; i++)
	{
		int arr[cols];
		printf("Enter elements in array %d:\n", i+1);
		for(int i=0; i<cols; i++)
			scanf("%d", &arr[i]);

		n = sendto(sockfd, arr, sizeof(arr), 0, (struct sockaddr_in*)&address, len);
	}

	return 0;
}