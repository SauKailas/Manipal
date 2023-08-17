#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

int main()
{
	int sd, x;
	//char buf[25];
	int row;
	int col;
	struct sockaddr_in sadd,cadd;
	sd=socket(AF_INET,SOCK_DGRAM,0);
	sadd.sin_family=AF_INET;
	sadd.sin_addr.s_addr=inet_addr("172.16.57.125");
	sadd.sin_port=htons(10200);

	int result=bind(sd,(struct sockaddr *)&sadd,sizeof(sadd));
	int len=sizeof(cadd);

	int m=recvfrom(sd,&row,sizeof(row),0,(struct sockaddr *)&cadd,&len);
	int n=recvfrom(sd,&col,sizeof(col),0,(struct sockaddr *)&cadd,&len);

	printf("Number of Rows: %d\n", row);
	printf("Number of Columns: %d\n", col);

	int arr[row][col];
	int rows[col];

	for(int i=0; i<row; i++)
	{
		x = recvfrom(sd, rows, sizeof(rows), 0, (struct sockaddr *)&cadd, &len);
		printf("Row %d: ", i+1);
		for(int j=0; j<col; j++)
		{
			printf("%d ",rows[j]);
			arr[i][j] = rows[j];
		}
		printf("\n");
	}

	printf("\nMatrix:\n");
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}

	return 0;
}