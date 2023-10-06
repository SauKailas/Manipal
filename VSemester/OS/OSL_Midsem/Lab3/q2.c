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
		printf("Error creating child process!\n");
		exit(-1);
	}
	else if(pid == 0)
	{
		printf("Executing child process of q1...\n");
		execlp("./q1", "q1", NULL);
		exit(0);
	}
	else
	{
		wait(&status);
		printf("Executing parent process...\n");
		printf("Child process returned: %d\n", status);
	}

	return 0;
}