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
		exit(1);
	}

	if((sfd = open(argv[2], O_RDONLY)) == -1)
	{
		printf("Cannot open file!\n");
		exit(1);
	}

	while(read(sfd, &chr, 1) > 0)
	{
		if(chr != '\n')
			ch[i++] = chr;
		else											// When a new line occurs, the character string is compared
		{
			k++;										// k indicates the row number
			ch[i] = '\0';
			i = 0;

			if(strstr(ch, argv[1]) != NULL)				// strstr is used to search a substring within a larger string
				printf("Line: %d \t %s \n", k, ch);
		}
	}

	return 0;
}