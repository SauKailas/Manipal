#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
	int infile, outfile;
	char chr;

	if(argc != 3)
	{
		printf("Not enough arguments!\n");
		exit(1);
	}

	if((infile = open(argv[1], O_RDONLY)) == -1)
	{
		printf("Cannot open file %s!\n", argv[1]);
		exit(1);
	}

	if((outfile = open(argv[2], O_WRONLY)) == -1)
	{
		printf("Cannot open file %s!\n", argv[2]);
		exit(1);
	}

	while(read(infile, &chr, 1) > 0)
		write(outfile, &chr, 1);



	return 0;
}