#include<stdio.h>
#include<math.h>
#include "mpi.h"

int main(int argc, char *argv[])
{
	int rank, size, base = 2;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	printf("Process %d of total %d processes: %.3lf!\n", rank, size, pow(base, rank));

	MPI_Finalize();

	return 0;
}