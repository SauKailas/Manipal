#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(int argc, char *argv[])
{
	struct stat sb;
	int ret;

	if(argc != 2)
	{
		printf("Not enough arguments!\n");
		exit(0);
	}

	ret = stat(argv[1], &sb);

	if(ret == 1)
	{
		printf("Error!\n");
		exit(0);
	}

	printf("File name: %s\n", argv[1]);
	printf("Inode of file: %ld\n", sb.st_ino);
	printf("Device Container ID: %ld\n", sb.st_dev);
	printf("Hard Links: %ld\n", sb.st_nlink);
	printf("User ID: %ld\n", sb.st_uid);
	printf("Group ID: %ld\n", sb.st_gid);
	printf("Device ID: %ld\n", sb.st_rdev);
	printf("Total Size: %ld\n", sb.st_size);
	printf("Block Size: %ld\n", sb.st_blksize);
	printf("Number of Blocks: %ld\n", sb.st_blocks);

	return 0;
}