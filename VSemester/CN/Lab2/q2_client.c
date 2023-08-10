#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int len, result, sockfd, n=1;
    struct sockaddr_in address;
    int a,b;
    char ch;
    int output;
    printf("Enter the operator: ");
    scanf("%c", &ch);
    printf("Enter the numbers: ");
    scanf("%d %d", &a, &b);
    

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family=AF_INET;
    address.sin_addr.s_addr=inet_addr("172.16.57.125"); 
    address.sin_port=htons(10205);
    len = sizeof(address);

    result=connect(sockfd,(struct sockaddr *)&address,len);

    if(result==-1)
    {
        perror("\nCLIENT ERROR");
        exit(1);
    }

    write(sockfd,&a,sizeof(a));
    write(sockfd,&b,sizeof(b));
    write(sockfd,&ch,sizeof(ch));
    printf("OUTPUT SENT BACK FROM SERVER IS ..... ");

    n = read(sockfd, &output, sizeof(output));
    printf("%d\n", output);
    printf("So, %d %c %d = %d\n", a, ch, b, output);
}