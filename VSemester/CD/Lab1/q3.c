#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *fptr1, *fptr2, *fptr3;
	char filename[100], c1, c2;

	printf("Enter the first file to open for reading: \n");
	scanf("%s", filename);
	fptr1 = fopen(filename, "r");
	if(fptr1 == NULL)
	{
		printf("Cannot open file %s \n", filename);
		exit(0);
	}

	printf("Enter the second file to open for reading: \n");
	scanf("%s", filename);
	fptr2 = fopen(filename, "r");
	if(fptr2 == NULL)
	{
		printf("Cannot open file %s \n", filename);
		exit(0);
	}

	printf("Enter the file to open for writing: \n");
	scanf("%s", filename);
	fptr3 = fopen(filename, "w+");

	while(1)
	{
		c1 = fgetc(fptr1);
		while(c1 != '\n')
		{
			if(c1 == EOF)
				break;
			fputc(c1, fptr3);
			c1 = fgetc(fptr1);
		}
		if(c1 != EOF)
			fputc('\n', fptr3);

		c2 = fgetc(fptr2);
		while(c2 != '\n')
		{
			if(c2 == EOF)
				break;
			fputc(c2, fptr3);
			c2 = fgetc(fptr2);
		}
		if(c2 != EOF)
			fputc('\n', fptr3);

		if(c1 == EOF && c2 == EOF)
			break;
	}

	printf("Contents successfully merged!\n");

	fclose(fptr1);
	fclose(fptr2);
	fclose(fptr3);

	return 0;
}