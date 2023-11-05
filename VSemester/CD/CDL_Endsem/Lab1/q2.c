#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *f1, *f2;
	char filename[100];
	char c;
	int size;
	int cur;

	printf("Enter the filename to open for reading: ");
	scanf("%s", filename);

	if((f1 = fopen(filename, "r")) == NULL)
	{
		printf("Cannot open file %s!\n", filename);
		exit(0);
	}

	printf("Enter the filename to open for writing: ");
	scanf("%s", filename);

	if((f2 = fopen(filename, "w")) == NULL)
	{
		printf("Cannot open file %s!\n", filename);
		exit(0);
	}

	c = fseek(f1, 0, SEEK_END);
	size = ftell(f1);

	printf("Size of file is: %d\n", size);

	cur = size - 1;

	while(cur >= 0)
	{
		fseek(f1, cur, SEEK_SET);
		c = fgetc(f1);
		fputc(c, f2);
		cur--;
	}

	printf("Contents Reversed Successfully!\n");

	fclose(f1);
	fclose(f2);

	return 0;
}