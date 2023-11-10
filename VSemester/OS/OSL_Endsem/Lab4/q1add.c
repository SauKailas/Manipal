#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<fcntl.h>
#include<unistd.h>
#include<time.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/wait.h>

const char *perms(mode_t mode)
{
	static char buf[16] = {0};
	int i = 0;

	buf[i++] = ((mode & S_IRUSR) ? 'r' : '-');
	buf[i++] = ((mode & S_IWUSR) ? 'w' : '-');
	buf[i++] = ((mode & S_IXUSR) ? 'x' : '-');
	buf[i++] = ((mode & S_IRGRP) ? 'r' : '-');
	buf[i++] = ((mode & S_IWGRP) ? 'w' : '-');
	buf[i++] = ((mode & S_IXGRP) ? 'x' : '-');
	buf[i++] = ((mode & S_IROTH) ? 'r' : '-');
	buf[i++] = ((mode & S_IWOTH) ? 'w' : '-');
	buf[i++] = ((mode & S_IXOTH) ? 'x' : '-');
}

int main(int argc, char *argv[])
{
	struct stat sb;
	DIR *dp;
	struct dirent *entry;
	int ret;

	if(argc < 2)
	{
		printf("Not enough arguments!\n");
		exit(0);
	}

	if((dp = opendir(argv[1])) == NULL)
	{
		printf("Cannot open directory!\n");
		exit(0);
	}

	while((entry = readdir(dp)) != NULL)
	{
		lstat(entry->d_name, &sb);

		if(S_ISDIR(sb.st_mode) == 0)
			printf("Inode of file %s: %ld\n", entry->d_name, sb.st_ino);
	}

	return 0;
}