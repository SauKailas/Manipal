#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define PORTNO 10200

int main()
{
    int sockfd,newsockfd,portno,clilen,n=1;
    int arr[5];
    struct sockaddr_in seraddr,cliaddr;
    int i,value;
    sockfd = socket(AF_INET,SOCK_STREAM,0);
    seraddr.sin_family = AF_INET;
    seraddr.sin_addr.s_addr = inet_addr("172.16.57.125");
    seraddr.sin_port = htons(PORTNO);
    bind(sockfd,(struct sockaddr *)&seraddr,sizeof(seraddr));
    listen(sockfd,5);

    while(1)
    {
        clilen = sizeof(clilen);
        newsockfd=accept(sockfd,(struct sockaddr *)&cliaddr,&clilen);
        if(fork()==0)
        {
            n = read(newsockfd,arr,sizeof(arr));
            printf("Received array successfully!\n");
            for(int i=0;i<4;i++)
            {
                int min=i;

                for(int j=i;j<5;j++)
                {
                    if(arr[j]<arr[min]) 
                        min=j;
                }

                if(i!=min)
                {
                    int temp=arr[i];
                    arr[i]=arr[min];
                    arr[min]=temp;
                }
            }

            n = write(newsockfd,arr,sizeof(arr));
            printf("Sent sorted array successfully!\n");
            int pid=getpid();
            n=write(newsockfd, &pid, sizeof(pid));
            close(newsockfd);
            exit(0);
        }
        else
            close(newsockfd);
    }
}