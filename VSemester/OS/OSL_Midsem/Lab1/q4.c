#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	int in_file, out_file;
	char ch;

	if(argc != 3)
	{
		printf("Not enough arguments!\n");
		exit(1);
	}

	if((in_file = open(argv[1], O_RDONLY)) == -1)
	{
		printf("Cannot open input file!\n");
		exit(1);
	}

	if((out_file = open(argv[2], O_WRONLY)) == -1)
	{
		printf("Cannot open output file!\n");
		exit(1);
	}

	while(read(in_file, &ch, 1) == 1)
		write(out_file, &ch, 1);

	printf("Contents copied successfully!\n");

	return 0;
}

