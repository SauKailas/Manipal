// Remove preprocessor directives.

#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *fptr1, *fptr2;
	char filename[100];
	char c;

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

	c = fgetc(fptr1);

	while(c != EOF)
	{
		if(c == '"')
		{	
			fputc(c, fptr2);
			c = fgetc(fptr1);

			while(c != '"')
			{
				fputc(c, fptr2);
				c = fgetc(fptr1);
			}
			fputc(c, fptr2);
			c = fgetc(fptr1);
		}
		else if(c == '/')
		{
			c = fgetc(fptr1);
			if(c == '/')
			{
				fputc(c, fptr2);
				while(c != '\n')
				{
					fputc(c, fptr2);
					c = fgetc(fptr1);
				}
			}
			else
			{
				fputc('/', fptr2);
				c = fgetc(fptr1);
			}
		}
		else if(c == '#')
		{
			while(c != '\n')
				c = fgetc(fptr1);
			fputc(c, fptr2);
			c = fgetc(fptr1);
		}
		else
		{
			fputc(c, fptr2);
			c = fgetc(fptr1);
		}
	}

	printf("Contents Modified Successfully!\n");

	fclose(fptr1);
	fclose(fptr2);

	return 0;
}