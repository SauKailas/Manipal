#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

#define PORTNO 10200

void sort(int arr[])
{
	for(int i=0; i<4; i++)
    {
        int min = i;

        for(int j=i; j<5; j++)
            if(arr[j] < arr[min]) 
                min = j;

        if(i != min)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

int main()
{
	struct sockaddr_in seraddr, cliaddr;
	int sockfd, newsockfd, clilen, n, pid;
	int arr[5];

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
			n = read(newsockfd, arr, sizeof(arr));
			printf("Received: ");
			for(int i=0; i<5; i++)
				printf("%d ", arr[i]);
			printf("\n");

			sort(arr);
			n = write(newsockfd, arr, sizeof(arr));
			printf("Sent: ");
			for(int i=0; i<5; i++)
				printf("%d ", arr[i]);
			printf("\n");

			pid = getpid();
			printf("PID: %d\n", pid);
			n = write(newsockfd, &pid, sizeof(pid));
		}
		else
			close(newsockfd);		
	}

	return 0;
}