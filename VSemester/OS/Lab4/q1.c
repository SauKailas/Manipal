#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(int argc, char *argv[])	// Argument count and arguments vector
{
	struct stat sb;		// sb is of type stat structure, it will be used to store information about the file
	int ret;			// Stores the return value of the stat function

	if(argc < 2)		// Checks whether there is atleast one command-line argument
	{
		printf("Filename not provided!\n");
		return 1;
	}

	ret = stat(argv[1], &sb);		// Parameters to the stat function are the name of the file and pointer to sb stat structure

	if(ret)							// If ret is not zero then some error has occured
	{
		perror("stat");
		return 1;
	}

	printf("Inode of file %s is %ld\n", argv[1], sb.st_ino);		// Print the inode of the given file

	return 0;
}