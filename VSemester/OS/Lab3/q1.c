#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	int status;													// Stores the exit status of the child process
	pid_t pid;													// Stores pid of the child process
	pid = fork();												// Creates a new child process

	if(pid == -1)												// Error occured during creation of child process
	{
		printf("Error in creating child process!\n");			
		exit(-1);												// Exit status for error is -1
	}
	else if(pid == 0)											// PID = 0 indicates code is executing in child process
	{
		printf("Executing child process...\n");
		exit(0);												// Exit status for child process is 0
	}
	else														// PID > 0 indicates code is executing in parent process
	{
		wait(&status);											// Parent waits till child completes execution
		printf("Executing parent process...\n");
		printf("Child process returned: %d\n", status);
	}

	return 0;
}