#include<stdio.h>
#include "mpi.h"

int isPrime(int n)
{
	if(n == 1)
		return 0;
	
	for(int i=2; i<n; i++)
		if(n % i == 0)
			return 0;
	return 1;
}

int main(int argc, char *argv[])
{
	int rank, size;
	int n;
	MPI_Status status;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	int arr[size];

	if(rank == 0)
	{
		printf("Enter the numbers: ");
		for(int i=0; i<size; i++)
			scanf("%d", &arr[i]);

		for(int i=1; i<size; i++)
			MPI_Ssend(&arr[i], 1, MPI_INT, i, i, MPI_COMM_WORLD);

		printf("Process %d of total %d processes: ", rank, size);
		if(isPrime(arr[rank]))
			printf("%d is prime!\n", arr[rank]);
		else
			printf("%d is not prime!\n", arr[rank]);
	}
	else
	{
		MPI_Recv(&n, 1, MPI_INT, 0, rank, MPI_COMM_WORLD, &status);
		printf("Process %d of total %d processes: ", rank, size);
		if(isPrime(n))
			printf("%d is prime!\n", n);
		else
			printf("%d is not prime!\n", n);
	}

	MPI_Finalize();

	return 0;
}