// Replace blank spaces and tabs with single space.

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
		if(c == ' ')					// Spaces
		{
			fputc(c, fptr2);
			while(c == ' ' || c == '\t')
				c = fgetc(fptr1);
		}
		else if(c == '\t')				// Tabs
		{
			fputc('\t', fptr2);
			while(c == ' ' || c == '\t')
				c = fgetc(fptr1);
		}
		else if(c == '"')				// Double Quotes
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
		else if(c == '#')				// Multiline Comment
		{
			while(c != '\n')
			{
				fputc(c, fptr2);
				c = fgetc(fptr1);
			}
			fputc(c, fptr2);
			c = fgetc(fptr1);
		}
		else if(c == '/')				// Singleline Comment
		{
			c = fgetc(fptr1);
			if(c == '/')
			{
				fputc('/', fptr2);
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
		else
		{
			fputc(c, fptr2);
			c = fgetc(fptr1);
		}
	}

	printf("Contents Successfully Modified!\n");

	fclose(fptr1);
	fclose(fptr2);

	return 0;
}