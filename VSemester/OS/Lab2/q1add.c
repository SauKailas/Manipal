#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

void sort(char array[][256], int len)
{
	char temp[256];

	for(int i=0; i<len; i++)
    	for(int j=0; j<len-1-i; j++){
    		if(strcmp(array[j], array[j+1]) > 0)
    		{
		        strcpy(temp, array[j]);
		        strcpy(array[j], array[j+1]);
		        strcpy(array[j+1], temp);
      		}
    }
}

void printdir(char *dir, int depth)
{
	char direc[30][256];
	int i=0;

	DIR *d;
	struct dirent *entry;
	struct stat statbuff;

	if((d = opendir(dir)) == NULL) 
	{
		printf("Incorrent directory path!\n"); 
		return;
	}

	chdir(dir);

	while((entry = readdir(d)) != NULL)
	{
		lstat(entry->d_name, &statbuff);

		if(S_ISDIR(statbuff.st_mode))
		{
			if(strcmp(".", entry->d_name) == 0 || strcmp("..", entry->d_name)== 0)
				continue;
			strcpy(direc[i++], entry->d_name);
		}
	}

	sort(direc, i);

	printf("Sorted Subdirectories:\n");
	for(int m=0; m<i; m++)
		printf("%s\n", direc[m]);
	printf("\n");

	chdir("..");
	closedir(d);
}

int main()
{
	char d[] = "/home/oslab/Documents/210905033/OSL/Lab2/sample_files";
	char* buff; 

	printdir(d, 0);

	return 0;
}