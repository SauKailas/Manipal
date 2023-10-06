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
		{
			printf("\n\nFile: %s\n", entry->d_name);
			printf("Inode: %ld\n", sb.st_ino);
			printf("Device Container ID: %ld\n", sb.st_dev);
			printf("Mode: %s\n", perms(sb.st_mode));
			printf("Hard Links: %ld\n", sb.st_nlink);
			printf("User ID: %ld\n", sb.st_uid);
			printf("Group ID: %ld\n", sb.st_gid);
			printf("Device ID: %ld\n", sb.st_rdev);
			printf("Total Size: %ld\n", sb.st_size);
			printf("Block Size: %ld\n", sb.st_blksize);
			printf("Number of Blocks: %ld\n", sb.st_blocks);
			printf("Last Access Time: %s", ctime(&sb.st_atime));
			printf("Last Modified Time: %s", ctime(&sb.st_mtime));
			printf("Last Status: %s", ctime(&sb.st_ctime));
		}
	}

	return 0;
}