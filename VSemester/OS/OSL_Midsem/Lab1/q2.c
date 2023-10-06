#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
	int file_idx = 1, sfd, i, k, p;
	char ch;
	char chr[100];

	if(argc < 2)
	{
		printf("Not enough arguments!\n");
		exit(1);
	}

	while(file_idx < argc)
	{
		i = 0;
		k = 0;
		p = 0;

		if((sfd = open(argv[file_idx], O_RDONLY)) == -1)
		{
			printf("Cannot open file %d!\n", file_idx);
			file_idx++;
			continue;
		}

		printf("\n\nFILE %d:\n\n", file_idx);

		while(read(sfd, &ch, 1) > 0)
		{
			if(ch != '\n')
				chr[i++] = ch;
			else
			{
				chr[i] = '\0';
				i = 0;
				k++;
				p++;

				printf("Line %d: %s\n", k, chr);

				if(p == 20)
				{
					fgetc(stdin);
					p = 0;
				}
			}
		}
		file_idx++;
	}

	return 0;
}