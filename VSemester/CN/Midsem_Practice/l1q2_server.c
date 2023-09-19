#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

#define PORTNO 10200

char* removeDuplicateWords(char *sentence)
{
    char words[100][100];
    int wordCount = 0;

    char *token = strtok(sentence, " ");
    
    while(token != NULL) {
        int isDuplicate = 0;
        
        for(int i=0; i<wordCount; i++) 
        {
            if(strcmp(words[i], token) == 0) 
            {
                isDuplicate = 1;
                break;
            }
        }

        if (!isDuplicate)
        {
            strcpy(words[wordCount], token);
            wordCount++;
        }
        
        token = strtok(NULL, " ");
    }
    
    char *result = (char*)malloc(1000);
    result[0] = '\0'; 
    
    for (int i=0; i<wordCount; i++) 
    {
        strcat(result, words[i]);
        if (i < wordCount - 1)
            strcat(result, " ");
    }
    
    return result;
}

int main()
{
    struct sockaddr_in seraddr, cliaddr;
    int sockfd, newsockfd, clilen, n;
    char buf[256];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    seraddr.sin_family = AF_INET;
    seraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    seraddr.sin_port = htons(PORTNO);

    bind(sockfd, (struct sockaddr*)&seraddr, sizeof(seraddr));

    listen(sockfd, 5);

    while(1)
    {
        newsockfd = accept(sockfd, (struct sockaddr*)&cliaddr, &clilen);

        n = read(newsockfd, buf, sizeof(buf));
        printf("Received: %s\n", buf);

        char *result = removeDuplicateWords(buf);

        n = write(newsockfd, result, strlen(result) + 1);
        printf("Sent: %s\n", result);
    }

    return 0;
}