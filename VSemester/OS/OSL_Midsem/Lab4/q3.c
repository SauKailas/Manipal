#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	struct stat sb1, sb2, sb3;
	int ret1, ret2, ret3, ret4, ret5;
	char *new_path = "q4stat.c";

	if(argc < 2)
	{
		printf("Not enough arguments!\n");
		exit(1);
	}

	ret1 = stat(argv[1], &sb1);

	if(ret1 == 1)
	{
		perror("Stat");
		exit(1);
	}

	printf("Current No. of Hard Links: %ld\n", sb1.st_nlink);

	printf("Linking %s to %s\n", argv[1], new_path);
	ret2 = link(argv[1], new_path);
	ret3 = stat(argv[1], &sb2);
	printf("Current No. of Hard Links: %ld\n", sb2.st_nlink);

	printf("Unlinking %s from %s\n", argv[1], new_path);
	ret4 = unlink(argv[1]);
	ret5 = stat(argv[1], &sb3);
	printf("Current No. of Hard Links: %ld\n", sb3.st_nlink);

	return 0;
}