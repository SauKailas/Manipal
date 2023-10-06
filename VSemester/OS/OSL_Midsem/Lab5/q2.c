#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<unistd.h>
#include<string.h>

int main()
{
	int fd[2], pipe_fd, res;
	char buffer[1000];
	char *data = "Saurabh Kailas is better than Messi!";

	pipe(fd);

	write(fd[1], data, strlen(data));

	res = read(fd[0], buffer, 1000);

	if(res != -1)
	{
		buffer[res] = 0;
		printf("Read %d bytes from the pipe: \t%s\n", res, buffer);
	}
	else
		exit(0);

	return 0;
}