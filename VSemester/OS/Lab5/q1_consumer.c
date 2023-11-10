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
	int open_mode = O_RDONLY;
	int res;
	char buffer[BUFFER_SIZE+1];	

	printf("Process %d opening FIFO %s O_RDONLY!\n", getpid(), FIFO_NAME);
	pipe_fd = open(FIFO_NAME, open_mode);

	if(pipe_fd != -1)
	{
		for(int i=0; i<4; i++)
		{
			res = read(pipe_fd, buffer, BUFFER_SIZE);
			printf("Received: %s\n", buffer);
		}
		close(pipe_fd);
	}
	else
		exit(0);

	return 0;
}