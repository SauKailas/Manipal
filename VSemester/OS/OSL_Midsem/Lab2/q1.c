#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<dirent.h>

int main()
{
	char pwd[256];
	DIR *dp;
	struct dirent *entry;						// Pointer to a directory entry structure
	struct stat statbuf;

	if(getcwd(pwd, sizeof(pwd)) == NULL)		// Store the current directory in the pwd array
	{
		printf("Cannot open directory!\n");
		exit(1);
	}

	if((dp = opendir(pwd)) == NULL)				// Open the directory specified in the pwd array
	{
		printf("Cannot open directory!\n");
		exit(1);
	}

	while((entry = readdir(dp)) != NULL)
	{
		lstat(entry->d_name, &statbuf);							// Retrieves file status information

		if(S_ISDIR(statbuf.st_mode) == 0)						// If it is not a directory then enter the if condition
		{	
			printf("%s\t\t", entry->d_name);					// Name of the file
			printf(S_ISDIR(statbuf.st_mode) ? "d": "-");
			printf((statbuf.st_mode & S_IRUSR) ? "r": "-");
			printf((statbuf.st_mode & S_IWUSR) ? "w": "-");
			printf((statbuf.st_mode & S_IXUSR) ? "x": "-");
			printf((statbuf.st_mode & S_IRGRP) ? "r": "-");
			printf((statbuf.st_mode & S_IWGRP) ? "w": "-");
			printf((statbuf.st_mode & S_IXGRP) ? "x": "-");
			printf((statbuf.st_mode & S_IROTH) ? "r": "-");
			printf((statbuf.st_mode & S_IWOTH) ? "w": "-");
			printf((statbuf.st_mode & S_IXOTH) ? "x": "-");
			printf("\n");
		}
	}

	return 0;
}	