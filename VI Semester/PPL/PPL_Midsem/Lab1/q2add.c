#include<stdio.h>
#include "mpi.h"

int isPrime(int n)
{
	for(int i=2; i<n; i++)
		if(n % i == 0)
			return 0;
	return 1;
}

int main(int argc, char *argv[])
{
	int rank, size;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	printf("The prime numbers are:\n");
	if(rank == 0)
	{
		for(int i=1; i<=50; i++)
			if(isPrime(i))
				printf("Process 0: %d\n", i);
	}
	else if(rank == 1)
	{
		for(int i=51; i<=100; i++)
			if(isPrime(i))
				printf("Process 1: %d\n", i);
	}

	MPI_Finalize();

	return 0;
}