#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *fptr;
	char filename[100], c;

	printf("Enter the filename to open for reading: \n");
	scanf("%s", filename);
	fptr = fopen(filename, "r");
	if(fptr == NULL)
	{
		printf("Cannot open file %s \n", filename);
		exit(0);
	}

	int line_count = 1;
	int char_count = 0;

	c = fgetc(fptr);
	while(c != EOF)
	{
		if(c == '\n')
			line_count++;
		else
			char_count++;
		c = fgetc(fptr);
	}

	printf("The number of lines is: %d\n", line_count);
	printf("The number of characters is: %d\n", char_count);

	fclose(fptr);

	return 0;
}