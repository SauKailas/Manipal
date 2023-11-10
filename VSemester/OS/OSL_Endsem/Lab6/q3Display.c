#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<unistd.h>
#include<fcntl.h>
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
	long int msg_to_rcv = 0;

	msgid = msgget((key_t)1234,0666 | IPC_CREAT);

	if(msgid == -1)
	{
		printf("msgget failed!\n");
		exit(0);
	}

	while(1)
	{
		if(msgrcv(msgid, (void*)&msg, BUFFER_SIZE, msg_to_rcv, 0) == -1)
		{
			printf("msgrcv failed!\n");
			exit(0);
		}

		if(strcmp(msg.message, "-1") == 0)
			break;

		printf("Received: %s\n", msg.message);
	}

	return 0;
}