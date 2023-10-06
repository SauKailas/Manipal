#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<dirent.h>

void Sort(char direc[][256], int n)
{
	char temp[256];

	for(int i=0; i<n; i++)
		for(int j=0; j<n-i-1; j++)
			if(strcmp(direc[j], direc[j+1]) > 0)
			{
				strcpy(temp, direc[j]);
				strcpy(direc[j], direc[j+1]);
				strcpy(direc[j+1], temp);
			}
}

void PrintSortedDir(char *dir)
{
	DIR *dp;
	struct dirent *entry;
	struct stat statbuf;
	char direc[30][256];
	int i = 0;

	if((dp = opendir(dir)) == NULL)
	{
		printf("Cannot open file!\n");
		return;
	}

	while((entry = readdir(dp)) != NULL)
	{
		lstat(entry->d_name, &statbuf);

		if(S_ISDIR(statbuf.st_mode))
		{
			if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
				continue;
			strcpy(direc[i++], entry->d_name);
		}
	}

	Sort(direc, i);

	printf("\nSorted Directories:\n\n");
	for(int j=0; j<i; j++)
		printf("%s\n", direc[j]);
	printf("\n");
	return;	
}

int main()
{
	PrintSortedDir("..");
	return 0;
}