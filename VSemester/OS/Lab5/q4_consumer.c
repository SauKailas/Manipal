#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/msg.h>

#define FIFO_NAME "my_fifo"
#define BUFFER_SIZE 1000

int main()
{
	int pipe_fd;
	int open_mode = O_WRONLY;
	int res;
	char buffer[BUFFER_SIZE+1];
	int demand;

	if(access(FIFO_NAME, F_OK) == -1)
	{
		res = mkfifo(FIFO_NAME, 0777);

		if(res == -1)
		{
			printf("Cannot open file %s!\n", FIFO_NAME);
			exit(0);
		}
	}

	printf("\nCommunicating with Producer...\n\n");

	while(1)
	{
		pipe_fd = open(FIFO_NAME, open_mode);
		printf("Enter demand: ");
		gets(buffer);
		res = write(pipe_fd, buffer, BUFFER_SIZE);
		res = close(pipe_fd);
	}

	res = close(pipe_fd);

	return 0;
}