#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *f;
	char filename[100];
	char c;
	int lines = 1, chars = 0;

	printf("Enter the filename to open for reading: ");
	scanf("%s", filename);

	if((f = fopen(filename, "r")) == NULL)
	{
		printf("Cannot open file %s!\n", filename);
		exit(0);
	}

	while((c = fgetc(f)) != EOF)
	{
		if(c == '\n')
			lines++;
		else
			chars++;
	}

	printf("Number of Lines: %d\n", lines);
	printf("Number of Characters: %d\n", chars);

	return 0;
}