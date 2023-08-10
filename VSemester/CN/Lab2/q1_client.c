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
    int arr[5];
    int pid;

    printf("Enter array elements: \n");
    for(int i=0; i<5; i++)
        scanf("%d", &arr[i]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family=AF_INET;
    address.sin_addr.s_addr=inet_addr("172.16.57.125"); 
    address.sin_port=htons(10200);
    len = sizeof(address);

    result=connect(sockfd,(struct sockaddr *)&address,len);

    if(result==-1)
    {
        perror("\nCLIENT ERROR");
        exit(1);
    }

    write(sockfd,arr,sizeof(arr));
    printf("Sorted array sent from server: ");

    n=read(sockfd,arr,sizeof(arr));
    for(int i=0; i<5; i++)
        printf("%d ", arr[i]);
    printf("\n");

    n=read(sockfd, &pid, sizeof(pid));
    printf("Process ID: %d\n", pid);
}