#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

int main()
{
	int sd, x;
	struct sockaddr_in address;
	sd=socket(AF_INET,SOCK_DGRAM,0);
	address.sin_family=AF_INET;
	address.sin_addr.s_addr=inet_addr("172.16.57.125");//**
	address.sin_port=htons(10200);

	int row;
	int col;

	printf("Enter the number of rows: ");
	scanf("%d", &row);
	printf("Enter the number of columns: ");
	scanf("%d", &col);

	int len=sizeof(address);

	int m = sendto(sd,&row,sizeof(row),0,(struct sockaddr *)&address, len);
	int n = sendto(sd,&col,sizeof(col),0,(struct sockaddr *)&address, len);

	int rows[col];
	for(int i=0; i<row; i++)
	{
		printf("Enter elements of row %d:\n", i+1);
		for(int j=0; j<col; j++)
			scanf("%d", &rows[j]);

		x = sendto(sd, rows, sizeof(rows), 0, (struct sockaddr *)&address, len);
	}

	return 0;
}