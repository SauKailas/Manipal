#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
	char pwd[256];
	DIR *dp;
	struct dirent *entry;
	struct stat statbuf;
	char ch;

	if(getcwd(pwd, sizeof(pwd)) == NULL)
	{
		printf("Cannot open directory!\n");
		exit(1);
	}

	if((dp = opendir(pwd)) == NULL)
	{
		printf("Cannot open directory!\n");
		exit(1);
	}

	while((entry = readdir(dp)) != NULL)
	{
		lstat(entry->d_name, &statbuf);

		if(S_ISDIR(statbuf.st_mode) == 0)
		{
			printf("Remove file %s (Y or N)? ", entry->d_name);
			scanf(" %c", &ch);

			if(ch == 'Y')
				remove(entry->d_name);
		}
	}

	return 0;
}