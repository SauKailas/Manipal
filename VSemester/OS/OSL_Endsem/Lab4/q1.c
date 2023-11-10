#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
	struct stat sb;
	int ret;

	if(argc < 2)
	{
		printf("Not enough arguments!\n");
		exit(1);
	}

	ret = stat(argv[1], &sb);

	if(ret == 1)
	{
		perror("Stat");
		return 1;
	}

	printf("Inode of file %s is %ld!\n", argv[1], sb.st_ino);

	return 0;
}