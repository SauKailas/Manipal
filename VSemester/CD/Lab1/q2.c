#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *fptr1, *fptr2;
	char filename[100], c;

	printf("Enter the filename to open for reading: \n");
	scanf("%s", filename);
	fptr1 = fopen(filename, "r");
	if(fptr1 == NULL)
	{
		printf("Cannot open file %s \n", filename);
		exit(0);
	}

	printf("Enter the file to open for writing: \n");
	scanf("%s", filename);
	fptr2 = fopen(filename, "w+");

	fseek(fptr1, 0, SEEK_END);
	long file_size = ftell(fptr1);
	printf("The file size is %ld\n", file_size);
	fseek(fptr1, 0, SEEK_SET);

	int cur = file_size - 1;
	char character;

	while(cur >= 0)
	{
		fseek(fptr1, cur, SEEK_SET);
		character = fgetc(fptr1);
		fputc(character, fptr2);
		cur--;
	}

	printf("Contents successfully reversed!\n");

	fclose(fptr1);
	fclose(fptr2);

	return 0;
}