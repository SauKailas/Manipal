#include<stdio.h>
#include "mpi.h"

int main(int argc, char *argv[])
{
	int rank, size;
	int N;
	MPI_Status status;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if(rank == 0)
	{
		printf("Enter a number: ");
		scanf("%d", &N);

		MPI_Ssend(&N, 1, MPI_INT, rank+1, 1, MPI_COMM_WORLD);
		MPI_Recv(&N, 1, MPI_INT, size-1, 1, MPI_COMM_WORLD, &status);

		printf("Process %d of total %d processes: %d\n", rank, size, N);
	}
	else
	{
		MPI_Recv(&N, 1, MPI_INT, rank-1, 1, MPI_COMM_WORLD, &status);
		printf("Process %d of total %d processes: %d\n", rank, size, N);
		N++;

		if(rank != size-2)
			MPI_Ssend(&N, 1, MPI_INT, rank+1, 1, MPI_COMM_WORLD);
		else
			MPI_Ssend(&N, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);
	}

	MPI_Finalize();

	return 0;
}