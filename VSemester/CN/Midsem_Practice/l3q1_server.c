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
	int sockfd, clilen, n, rows, cols;

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);

	seraddr.sin_family = AF_INET;
	seraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	seraddr.sin_port = htons(PORTNO);

	bind(sockfd, (struct sockaddr_in*)&seraddr, sizeof(seraddr));

	clilen = sizeof(cliaddr);

	n = recvfrom(sockfd, &rows, sizeof(rows), 0, (struct sockaddr_in*)&cliaddr, &clilen);
	n = recvfrom(sockfd, &cols, sizeof(cols), 0, (struct sockaddr_in*)&cliaddr, &clilen);
	printf("Number of Rows: %d\n", rows);
	printf("Number of Columns: %d\n", cols);

	int arr[cols];
	int res[rows][cols];
	int row_idx = 0, col_idx;

	for(int i=0; i<rows; i++)
	{
		col_idx = 0;
		n = recvfrom(sockfd, arr, sizeof(arr), 0, (struct sockaddr_in*)&cliaddr, &clilen);
		printf("Received array %d: ", i+1);
		for(int i=0; i<cols; i++)
		{
			printf("%d ", arr[i]);
			res[row_idx][col_idx++] = arr[i];
		}
		row_idx++;
		printf("\n");

	}

	printf("\n\nRESULTANT MATRIX:\n\n");
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
			printf("%d ", res[i][j]);
		printf("\n");
	}

	return 0;
}