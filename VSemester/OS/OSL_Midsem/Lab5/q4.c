#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *file;
	int n = 0;

	file = fopen("my_binary_file.bin", "wb+");

	printf("Enter 4 numbers: ");
	for(int i=0; i<4; i++)
	{
		scanf("%d", &n);
		fwrite(&n, sizeof(int), 1, file);
	}

	printf("Writing Complete!\n");
	fclose(file);

	printf("Now reading the binary file...\n");

	file = fopen("my_binary_file.bin", "rb");

	for(int i=0; i<4; i++)
	{
		fread(&n, sizeof(int), 1, file);
		printf("%d\n", n);
	}

	fclose(file);

	return 0;
}