#include<stdio.h>
#include "mpi.h"

int Factorial(int n)
{
	if(n == 1)
		return 1;
	return n * Factorial(n-1);
}

int main(int argc, char *argv[])
{
	int rank, size;
	int temp, fact, ans = 0;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	int arr[size], facts[size];

	if(rank == 0)
	{
		printf("Enter %d elements: ", size);
		for(int i=0; i<size; i++)
			scanf("%d", &arr[i]);
	}

	MPI_Scatter(arr, 1, MPI_INT, &temp, 1, MPI_INT, 0, MPI_COMM_WORLD);

	fact = Factorial(temp);

	MPI_Gather(&fact, 1, MPI_INT, facts, 1, MPI_INT, 0, MPI_COMM_WORLD);

	if(rank == 0)
	{	
		for(int i=0; i<size; i++)
		{
			printf("Process %d: %d\n", i, facts[i]);
			ans += facts[i];
		}
		printf("Sum of all factorials: %d\n", ans);
	}

	MPI_Finalize();

	return 0;
}