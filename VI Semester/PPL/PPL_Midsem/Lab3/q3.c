#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "mpi.h"

int countVowels(char str[], int n)
{
	int count = 0;
	for(int i=0; i<n; i++)
		if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' 
			|| str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
			count++;
	return count;
}

int main(int argc, char *argv[])
{
	int rank, size;
	int chunksize, vowels, vowelcount[100], totvowels = 0;
	char str[100], buf[100];

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if(rank == 0)
	{
		printf("Enter a string:\n");
		scanf("%s", str);

		if(strlen(str) % size != 0)
		{
			printf("String length not divisible by %d!\n", size);
			exit(1);
		}
		chunksize = strlen(str) / size;
	}

	MPI_Bcast(&chunksize, 1, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Scatter(str, chunksize, MPI_CHAR, buf, chunksize, MPI_CHAR, 0, MPI_COMM_WORLD);

	vowels = countVowels(buf, chunksize);

	MPI_Gather(&vowels, 1, MPI_INT, vowelcount, 1, MPI_INT, 0, MPI_COMM_WORLD);

	if(rank == 0)
	{
		for(int i=0; i<size; i++)
		{
			printf("Process %d: %d\n", i, vowelcount[i]);
			totvowels += vowelcount[i];
		}
		printf("Total Vowel Count: %d!\n", totvowels);
	}

	MPI_Finalize();

	return 0;
}