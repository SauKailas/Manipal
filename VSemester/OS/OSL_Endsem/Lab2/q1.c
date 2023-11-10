#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<dirent.h>

int main(
{
	char pwd[256];
	DIR *dp;
	struct dirent *entry;
	struct stat statbuf;

	if(getcwd(pwd, sizeof(pwd)) == NULL)
	{
		printf("Cannot open directory!\n");
		exit(0);
	}

	if((dp = opendir(pwd)) == NULL)
	{
		printf("Cannot open directory!\n");
		exit(0);
	}

	while((entry = readdir(dp)) != NULL)
	{
		lstat(entry->d_name, &statbuf);

		if(S_ISDIR(statbuf.st_mode) == 0)
		{
			printf("%s\t\t", entry->d_name);
			printf((statbuf.st_mode & S_IRUSR) ? "r" : "-");
			printf((statbuf.st_mode & S_IWUSR) ? "w" : "-");
			printf((statbuf.st_mode & S_IXUSR) ? "x" : "-");
			printf((statbuf.st_mode & S_IRGRP) ? "r" : "-");
			printf((statbuf.st_mode & S_IWGRP) ? "w" : "-");
			printf((statbuf.st_mode & S_IXGRP) ? "x" : "-");
			printf((statbuf.st_mode & S_IROTH) ? "r" : "-");
			printf((statbuf.st_mode & S_IWOTH) ? "w" : "-");
			printf((statbuf.st_mode & S_IXOTH) ? "x" : "-");
			printf("\n");
		}
	}

	return 0;
}