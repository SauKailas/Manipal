#include<stdio.h>
#include "mpi.h"

int main(int argc, char *argv[])
{
	int rank, size;
	int arr[20], num;
	MPI_Status status;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if(rank == 0)
	{
		printf("Enter %d elements: ", size);
		for(int i=0; i<size; i++)
			scanf("%d", &arr[i]);

		for(int i=1; i<size; i++)
			MPI_Send(&arr[i], 1, MPI_INT, i, i, MPI_COMM_WORLD);
	}
	else
	{
		MPI_Recv(&num, 1, MPI_INT, 0, rank, MPI_COMM_WORLD, &status);
		printf("Process %d of total %d processes: %d\n", rank, size, num);
	}

	MPI_Finalize();

	return 0;
}