#include<stdio.h>
#include "mpi.h"

int Factorial(int n)
{
	if(n == 1)
		return 1;
	return n * Factorial(n-1);
}

int Sum(int n)
{
	if(n == 1)
		return 1;
	return n + Sum(n-1);
}

int main(int argc, char *argv[])
{
	int rank, size;
	MPI_Status status;
	int n, temp, finalsum = 0;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	int arr[size], ans[size];

	if(rank == 0)
	{
		printf("Enter %d elements: ", size);
		for(int i=0; i<size; i++)
			scanf("%d", &arr[i]);

		for(int i=1; i<size; i++)
			MPI_Ssend(&arr[i], 1, MPI_INT, i, i, MPI_COMM_WORLD);

		ans[0] = 1;

		for(int i=1; i<size; i++)
		{
			MPI_Recv(&temp, 1, MPI_INT, i, i, MPI_COMM_WORLD, &status);
			ans[i] = temp;
		}

		for(int i=0; i<size; i++)
			finalsum += ans[i];

		printf("Final Sum: %d\n", finalsum);
	}
	else
	{
		MPI_Recv(&n, 1, MPI_INT, 0, rank, MPI_COMM_WORLD, &status);

		if(rank % 2 == 0)
		{
			temp = Factorial(n);
			MPI_Ssend(&temp, 1, MPI_INT, 0, rank, MPI_COMM_WORLD);
		}
		else
		{
			temp = Sum(n);
			MPI_Ssend(&temp, 1, MPI_INT, 0, rank, MPI_COMM_WORLD);
		}
	}

	MPI_Finalize();

	return 0;
}