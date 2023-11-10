#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<limits.h>
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

	if(access(FIFO_NAME, F_OK) == -1)
	{
		res = mkfifo(FIFO_NAME, 0777);

		if(res == -1)
		{
			printf("Cannot open file %s!\n", FIFO_NAME);
			exit(0);
		}
	}

	printf("Process %d opening FIFO %s O_WRONLY!\n", getpid(), FIFO_NAME);
	pipe_fd = open(FIFO_NAME, open_mode);

	if(pipe_fd != -1)
	{
		printf("Enter 4 numbers:\n");

		for(int i=0; i<4; i++)
		{
			scanf("%s", buffer);
			res = write(pipe_fd, buffer, BUFFER_SIZE);

			if(res == -1)
			{
				printf("Write error on pipe!\n");
				exit(0);
			}
		}
		close(pipe_fd);
	}
	else
		exit(0);

	return 0;
}