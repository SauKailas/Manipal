#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<unistd.h>

void Sort(char directories[][256], int n)
{
	char temp[256];

	for(int i=0; i<n; i++)
		for(int j=0; j<n-i-1; j++)
			if(strcmp(directories[j], directories[j+1]) > 0)
			{
				strcpy(temp, directories[j]);
				strcpy(directories[j], directories[j+1]);
				strcpy(directories[j+1], temp);
			}
}

void PrintSortedDirec(char *dir)
{
	DIR *dp;
	struct dirent *entry;
	struct stat statbuf;
	char directories[30][256];
	int i = 0;

	if((dp = opendir(dir)) == NULL)
	{
		printf("Cannot open directory %s!\n", dir);
		exit(0);
	}

	while((entry = readdir(dp)) != NULL)
	{
		lstat(entry->d_name, &statbuf);

		if(S_ISDIR(statbuf.st_mode))
		{
			if(strcmp(entry->d_name, "..") == 0 || strcmp(entry->d_name, ".") == 0)
				continue;
			strcpy(directories[i++], entry->d_name);
		}
	}

	Sort(directories, i);

	printf("\nSortedDirectories:\n\n");
	for(int j=0; j<i; j++)
		printf("%s\n", directories[j]);
	printf("\n");
	return;
}

int main()
{
	PrintSortedDirec("..");
	return 0;
}