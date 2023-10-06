#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<unistd.h>
#include<dirent.h>
#include<fcntl.h>
#include<time.h>
#include<sys/msg.h>

#define FIFO_NAME "my_queue"

int main()
{
	int res, pipe_fd;
	char buffer[1000];

	printf("Process %d opening FIFO O_RDONLY!\n", getpid());
	pipe_fd = open(FIFO_NAME, O_RDONLY);

	if(pipe_fd != -1)
	{
		for(int i=0; i<4; i++)
		{
			printf("%d: ", i+1);
			res = read(pipe_fd, buffer, 1000);
			printf("%s\n", buffer);
		}
		close(pipe_fd);
	}
	else
		exit(0);

	printf("Process %d finished!\n", getpid());

	return 0;
}