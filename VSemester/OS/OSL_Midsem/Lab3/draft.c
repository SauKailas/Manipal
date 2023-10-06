#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<fcntl.h>

int main()
{
	int status;
	pid_t pid;
	pid = fork();

	if(pid == -1)
	{
		printf("Error in creating child process!\n");
		exit(-1);
	}
	else if(pid == 0)
	{
		printf("Executing child process...\n");
		exit(0);
	}
	else
	{
		sleep(0);
		printf("Executing parent process...\n");
		printf("Child process returned: %d\n", status);
		printf("Exiting parent process...\n");
	}

	return 0;
}