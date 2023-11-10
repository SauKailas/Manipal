#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<dirent.h>

void PrintDir(char *dir, int depth)
{
	DIR *dp;
	struct dirent *entry;
	struct stat statbuf;

	if((dp = opendir(dir)) == NULL)
	{
		printf("Cannot open directory!\n");
		return;
	}
	chdir(dir);

	while((entry = readdir(dp)) != NULL)
	{
		lstat(entry->d_name, &statbuf);

		if(S_ISDIR(statbuf.st_mode))
		{
			if(strcmp(entry->d_name, "..") == 0 || strcmp(entry->d_name, ".") == 0)
				continue;
			printf("Depth %d: %s\n", depth, entry->d_name);
			PrintDir(entry->d_name, depth+4);
		}
		else
			printf("Depth %d: %s\n", depth, entry->d_name);
	}
	chdir("..");
	closedir(dp);
}

int main()
{
	PrintDir("..", 0);
	return 0;
}