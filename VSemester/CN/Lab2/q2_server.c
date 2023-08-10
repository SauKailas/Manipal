#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define PORTNO 10205

int main()
{
    int sockfd, newsockfd, portno, clilen, n=1;
    int a, b;
    char ch;
    int output;
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
        if(fork()==0){
            n = read(newsockfd,&a,sizeof(a));
            n = read(newsockfd,&b,sizeof(b));
            n = read(newsockfd,&ch,sizeof(ch));

            printf("Received: %d and %d and %c",a,b,ch);

            if (ch=='+')
                output = a + b;
            else if (ch == '-')
                output = a - b;
            else if (ch == '*')
                output = a*b;
            else if (ch == '/')
                output = a / b;
            else
                printf("Invalid output\n");

            n = write(newsockfd,&output,sizeof(output));
            close(newsockfd);
            exit(0);
        }
        else
            close(newsockfd);
    }
}