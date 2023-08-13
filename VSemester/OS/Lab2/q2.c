#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

void printdir(char *dir, int depth)
{
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
			printf("%*s%s:\n", depth,"",entry->d_name);
			printdir(entry->d_name, depth+4);
		}
		else
			printf("%*s%s\n", depth,"", entry->d_name);
	}
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