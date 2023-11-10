 #include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
	int sfd, i = 0, k = 0;
	char chr;
	char ch[100];

	if(argc != 3)
	{
		printf("Not enough arguments!\n");
		exit(0);
	}

	if((sfd = open(argv[1], O_RDONLY)) == -1)
	{
		printf("Cannot open file %s!\n", argv[1]);
		exit(0);
	}

	while(read(sfd, &chr, 1) > 0)
	{
		if(chr != '\n')
			ch[i++] = chr;
		else
		{
			ch[i] = '\0';
			i = 0;
			k++;

			if(strstr(ch, argv[2]) != NULL)
				printf("Line %d: %s\n", k, ch);
		}
	}

	return 0;
}