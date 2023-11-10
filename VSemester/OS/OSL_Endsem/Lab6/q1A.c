#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<limits.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/msg.h>

#define BUFFER_SIZE 1000

struct message
{
	long int message_type;
	char message[BUFFER_SIZE+1];
};

int main()
{
	struct message msg;
	int msgid;
	int running = 1;
	char buffer[BUFFER_SIZE+1];

	msgid = msgget((key_t)1234,0666 | IPC_CREAT);

	if(msgid == -1)
	{
		printf("msgget failed!\n");
		exit(0);
	}

	printf("\nEnter -1 to quit!\n\n");

	while(running)
	{
		printf("Enter a number: ");
		scanf("%s", buffer);

		if(strcmp(buffer, "-1") == 0)
			running = 0;

		msg.message_type = 1;
		strcpy(msg.message, buffer);

		if(msgsnd(msgid, (void*)&msg, BUFFER_SIZE, 0) == -1)
		{
			printf("msgsnd failed!\n");
			exit(0);
		}
	}

	return 0;
}