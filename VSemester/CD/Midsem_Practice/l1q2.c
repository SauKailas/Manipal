// Reverse contents and store in another file.

#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *fptr1, *fptr2;
	char filename[100];
	char c;
	long file_size;
	int cur;

	printf("Enter the filename to open for reading:\n");
	scanf("%s", filename);

	fptr1 = fopen(filename, "r");

	if(fptr1 == NULL)
	{
		printf("Cannot open file!\n");
		exit(0);
	}

	printf("Enter the filename to open for writing:\n");
	scanf("%s", filename);

	fptr2 = fopen(filename, "w+");

	fseek(fptr1, 0, SEEK_END);
	file_size = ftell(fptr1);

	printf("File size: %ld\n", file_size);

	cur = file_size - 1;

	while(cur >= 0)
	{
		fseek(fptr1, cur, SEEK_SET);
		c = fgetc(fptr1);
		fputc(c, fptr2);
		cur --;
	}

	printf("Contents Reversed Successfully!\n");

	fclose(fptr1);
	fclose(fptr2);

	return 0;
}