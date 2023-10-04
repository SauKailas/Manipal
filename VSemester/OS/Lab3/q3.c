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
		printf("PID: %d\nParent PID: %d\nChild PID: %d\n", getpid(), getppid(), pid);
		exit(0);
	}
	else
	{
		wait(&status);
		printf("\nExecuting parent process...\n");
		printf("PID: %d\nParent PID: %d\nChild PID: %d\n", getpid(), getppid(), pid);
	}

	return 0;
}