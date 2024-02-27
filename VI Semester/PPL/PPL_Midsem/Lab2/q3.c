#include<stdio.h>
#include<stdlib.h>
#include "mpi.h"
#define BUFFER_SIZE 100

int main(int argc, char *argv[])
{
	int rank, size;
	int bsize, num;
	int *buf;
	MPI_Status status;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	int arr[size-1];

	if(rank == 0)
	{
		printf("Enter %d numbers: ", size-1);
		for(int i=0; i<size-1; i++)
			scanf("%d", &arr[i]);
		bsize = MPI_BSEND_OVERHEAD + size;
		buf = (int*)malloc(bsize);
		MPI_Buffer_attach(buf, bsize);

		for(int i=0; i<size-1; i++)
			MPI_Bsend(&arr[i], 1, MPI_INT, i+1, i+1, MPI_COMM_WORLD);

		MPI_Buffer_detach(&buf, &bsize);
	}
	else
	{
		MPI_Recv(&num, 1, MPI_INT, 0, rank, MPI_COMM_WORLD, &status);
		if(rank % 2 == 0)
			printf("Process %d of total %d processes: %d\n", rank, size, num*num);
		else
			printf("Process %d of total %d processes: %d\n", rank, size, num*num*num);
	}

	MPI_Finalize();

	return 0;
}