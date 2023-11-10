#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

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
		wait(&status);
		printf("Child returned: %d!\n", status);
		printf("Executing parent process...\n");
	}

	return 0;
}