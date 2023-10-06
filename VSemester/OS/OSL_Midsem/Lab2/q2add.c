#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<dirent.h>
#include<unistd.h>

void DeleteFiles(char *dir)
{
	DIR *dp;
	struct dirent *entry;
	struct stat statbuf;
	char ch;

	if((dp = opendir(dir)) == NULL)
	{
		printf("Cannot open directory!\n");
		return;
	}

	while((entry = readdir(dp)) != NULL)
	{
		lstat(entry->d_name, &statbuf);

		if(S_ISDIR(statbuf.st_mode) == 0)
		{
			printf("Do you want to remove %s (Y or N): ", entry->d_name);
			scanf(" %c", &ch);

			if(ch == 'Y')
				remove(entry->d_name);
		}
	}
}

int main()
{
	DeleteFiles(".");
	return 0;
}