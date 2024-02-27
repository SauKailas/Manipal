#include<stdio.h>
#include<string.h>
#include "mpi.h"

int main(int argc, char *argv[])
{
	int rank, size;
	char word[20];
	int len;
	MPI_Status status;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if(rank == 0)
	{
		printf("Enter a word: ");
		scanf("%s", word);

		len = strlen(word);
		MPI_Ssend(&len, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
		MPI_Ssend(word, len, MPI_CHAR, 1, 1, MPI_COMM_WORLD);
		printf("Process %d sent: %s\n", rank, word);
		MPI_Recv(word, len, MPI_CHAR, 1, 2, MPI_COMM_WORLD, &status);
		printf("Process %d received: %s\n", rank, word);

	}
	else if(rank == 1)
	{
		MPI_Recv(&len, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
		MPI_Recv(word, len, MPI_CHAR, 0, 1, MPI_COMM_WORLD, &status);
		printf("Process %d received: %s\n", rank, word);

		for(int i=0; i<len; i++)
		{
			if(word[i] >= 'A' && word[i] <= 'Z')
				word[i] += 32;
			else
				word[i] -= 32;
		}

		MPI_Ssend(word, len, MPI_CHAR, 0, 2, MPI_COMM_WORLD);
		printf("Process %d sent: %s\n", rank, word);
	}

	MPI_Finalize();

	return 0;
}