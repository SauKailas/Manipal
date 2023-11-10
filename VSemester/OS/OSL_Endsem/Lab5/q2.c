#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/msg.h>
#include<sys/ipc.h>

#define BUFFER_SIZE 1000

int main()
{
	int pipe_fd[2];
	int res;
	char buffer[BUFFER_SIZE+1];
	char *data = "My name is Saurabh Kailas";

	pipe(pipe_fd);

	res = write(pipe_fd[1], data, strlen(data));
	printf("Wrote to pipe: %s\n", data);

	res = read(pipe_fd[0], buffer, BUFFER_SIZE);
	printf("Read from pipe: %s\n", buffer);

	return 0;
}