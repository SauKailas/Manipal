#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define PORTNO 10200

int main()
{
	int sockfd, newsockfd, portno, clilen, n=1;
	struct sockaddr_in seraddr, cliaddr;
	int i, value;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	seraddr.sin_family = AF_INET;
	seraddr.sin_addr.s_addr = inet_addr("172.16.57.43");
	seraddr.sin_port = htons(PORTNO);
    bind(sockfd,(struct sockaddr *)&seraddr,sizeof(seraddr));

    listen(sockfd, 5);

    while (1) {

		char str[256];
		printf("server waiting");
		
		clilen = sizeof(clilen);
		newsockfd=accept(sockfd,(struct sockaddr *)&cliaddr, &clilen);
		
		n = read(newsockfd,str,sizeof(str));

		printf(" \nMessage from Client %s \n",str);

		int size = strlen(str);

		char words[30][30];

	    int i=0, row=0, column=0;

	    while(str[i]!='\0')
	    {
	    	if(str[i]==' ') 
	    	{
	    		words[row][column] = '\0';
	    		row++;
	    		column=0;
	    	}
	    	else
	    	{
	    		words[row][column] = str[i];
	    		column++;
	    	}
	    	i++;
	    }

	    words[row][column] = '\0';


		int j = 0;
		for(int i=0; i<row; i++)
		{
			int present = 0;
			for(int l=1; l<row+1; l++)
			{
				if(words[l][j]=='\0' || l==i)
					continue;
				if(strcmp(words[i], words[l])==0) {
					words[l][j]='\0';
					present=present+1;
				}
			}
		}

		printf("\n\nMessage without Repeated Words  ");
		j=0;
		for(i=0; i<row+1; i++)
		{
			if(words[i][j]=='\0')
				continue;
			else
				printf("%s ", words[i]);
		}
		printf("\n");	

	}
}