#include<stdio.h>

int main()
{
	char filename[100];

	WRITE("Enter the filename: ");
	READ("%s", filename);

	return 0;
}