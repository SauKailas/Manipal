#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
	int in_file, out_file;
	char chr;

	if(argc != 3)
	{
		printf("Not enough arguments!\n");
		exit(0);
	}

	if((in_file = open(argv[1], O_RDONLY)) == -1)
	{
		printf("Cannot open file %s!\n", argv[1]);
		exit(0);
	}

	if((out_file = open(argv[2], O_WRONLY)) == -1)
	{
		printf("Cannot open file %s!\n", argv[2]);
		exit(0);
	}

	while(read(in_file, &chr, 1) > 0)
		write(out_file, &chr, 1);

	printf("Contents Copied Successfully!\n");

	return 0;
}