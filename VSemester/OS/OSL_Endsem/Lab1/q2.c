#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
	int file_idx = 1;
	int sfd;
	char chr;
	char ch[100];

	if(argc < 2)
	{
		printf("Not enough arguments!\n");
		exit(0);
	}

	while(file_idx < argc)
	{
		int p = 0;
		int i = 0;

		if((sfd = open(argv[file_idx], O_RDONLY)) == -1)
		{
			printf("Cannot open file %s!\n", argv[file_idx]);
			file_idx++;
			continue;
		}

		printf("\n\nFILE %d OPENED!\n\n", file_idx);

		while(read(sfd, &chr, 1) > 0)
		{
			if(chr != '\n')
				ch[i++] = chr;
			else
			{
				ch[i] = '\0';
				i = 0;
				p++;

				printf("Line %d: %s\n", p, ch);

				if(p == 20)
				{
					p = 0;
					fgetc(stdin);
				}
			}
		}
		file_idx++;
	}

	return 0;
}