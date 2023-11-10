#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>

int main()
{
	char pwd[256];
	DIR *dp;
	struct dirent *entry;
	struct stat statbuf;
	char c;

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
			printf("Do you want to remove %s (y or n): ", entry->d_name);
			scanf(" %c", &c);

			if(c == 'y')
				remove(entry->d_name);
		}
	}

	return 0;
}