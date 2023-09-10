// Count the number of lines and characters in a file.

#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *fptr;
	char filename[100];
	char c;

	printf("Enter the filename to open for reading:\n");
	scanf("%s", filename);

	fptr = fopen(filename, "r");

	if(fptr == NULL)
	{
		printf("Cannot open file!\n");
		exit(0);
	}

	int line_count = 1, char_count = 0;

	c = fgetc(fptr);

	while(c != EOF)
	{
		if(c == '\n')
			line_count++;
		else
			char_count++;
		c = fgetc(fptr);
	}

	printf("Line Count: %d\n", line_count);
	printf("Character Count: %d\n", char_count);

	fclose(fptr);

	return 0;
}